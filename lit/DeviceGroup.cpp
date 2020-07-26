#include "pch.h"
#include "DeviceGroup.h"

using namespace std;
using namespace lit;

bool lit::DeviceGroup::insert(shared_ptr<Device>& devicePtr)
{
    // counts how many devices are inserted without a name
    static int unnanimousCount = 0;

    // Make sure every device has a name
    if (devicePtr->alias().empty()) {
        devicePtr->alias() = "dev" + to_string(unnanimousCount++);
    }

    const alias_t& alias = devicePtr->alias();
    const endpoint_t& ep = devicePtr->endpoint();
    const ip_address_t& ip = ep.address();

    auto aliasIter = aliasMap.find(alias);
    auto endpointIter = endpointMap.find(ep);
    auto ipAddressIter = ipAddressMap.find(ip);

    if (aliasIter == aliasMap.end() && endpointIter == endpointMap.end() && ipAddressIter == ipAddressMap.end()) {
        aliasMap.insert({ alias, devicePtr });
        endpointMap.insert({ ep, devicePtr });
        ipAddressMap.insert({ ip, devicePtr });

        return true;    // device was added successfully
    }
    else {
        return false;    // device was not added successfully
    }
}

void lit::DeviceGroup::erase(shared_ptr<Device>& devicePtr)
{
    erase(*devicePtr);
}

void lit::DeviceGroup::erase(const Device& device)
{
    const alias_t& alias = device.alias();
    const endpoint_t& ep = device.endpoint();
    const ip_address_t& ip = device.endpoint().address();

    aliasMap.erase(alias);
    endpointMap.erase(ep);
    ipAddressMap.erase(ip);
}

boost::optional<const Device&> lit::DeviceGroup::getByAlias(const alias_t& alias) const
{
    auto iter = aliasMap.find(alias);

    if (iter != aliasMap.end()) {
        return *(iter->second);
    }
    else {
        return boost::optional<const Device&>();
    }
}

boost::optional<const Device&> lit::DeviceGroup::getByEndpoint(const endpoint_t& ep) const
{
    auto iter = endpointMap.find(ep);

    if (iter != endpointMap.end()) {
        return *(iter->second);
    }
    else {
        return boost::optional<const Device&>();
    }
}

boost::optional<const Device&> lit::DeviceGroup::getByIpAddress(const ip_address_t& ip) const
{
    auto iter = ipAddressMap.find(ip);

    if (iter != ipAddressMap.end()) {
        return *(iter->second);
    }
    else {
        return boost::optional<const Device&>();
    }
}

shared_ptr<Device> lit::DeviceGroup::pullByAlias(const alias_t& alias)
{
    auto aliasIter = aliasMap.find(alias);

    if (aliasIter == aliasMap.end()) {
        return shared_ptr<Device>();    // return nullptr
    }
    else {
        shared_ptr<Device> devicePtr = aliasIter->second;
        
        erase(*devicePtr);

        return devicePtr;
    }
}

shared_ptr<Device> lit::DeviceGroup::pullByEndpoint(const endpoint_t& ep)
{
    auto endpointIter = endpointMap.find(ep);

    if (endpointIter == endpointMap.end()) {
        return shared_ptr<Device>();    // return nullptr
    }
    else {
        shared_ptr<Device> devicePtr = endpointIter->second;

        erase(*devicePtr);

        return devicePtr;
    }
}

shared_ptr<Device> lit::DeviceGroup::pullByIpAddress(const ip_address_t& ip)
{
    auto ipAddressIter = ipAddressMap.find(ip);

    if (ipAddressIter == ipAddressMap.end()) {
        return shared_ptr<Device>();    // return nullptr
    }
    else {
        shared_ptr<Device> devicePtr = ipAddressIter->second;

        erase(*devicePtr);

        return devicePtr;
    }
}

void lit::DeviceGroup::changeAlias(const alias_t& currAlias, const alias_t& newAlias)
{
    shared_ptr<Device> devicePtr = pullByAlias(currAlias);

    if (devicePtr != nullptr) {
        devicePtr->alias() = newAlias;

        insert(devicePtr);
    }
}

void lit::DeviceGroup::changeEndpoint(const endpoint_t& currEp, const endpoint_t& newEp)
{
    shared_ptr<Device> devicePtr = pullByEndpoint(currEp);

    if (devicePtr != nullptr)
    {
        devicePtr->endpoint() = newEp;

        insert(devicePtr);
    }
}

void lit::DeviceGroup::changeIpAddress(const ip_address_t& currIp, const ip_address_t& newIp)
{
    shared_ptr<Device> devicePtr = pullByIpAddress(currIp);

    if (devicePtr != nullptr)
    {
        devicePtr->endpoint().address() = newIp;

        insert(devicePtr);
    }
}

list<shared_ptr<const Device>> lit::DeviceGroup::getActiveDevices() const
{
    list<shared_ptr<const Device>> activeDevices;

    for (const auto & iter : aliasMap) {
        const shared_ptr<Device>& devicePtr = iter.second;

        if (devicePtr->isActive()) {
            activeDevices.push_back(devicePtr);
        }
    }

    return activeDevices;
}

list<shared_ptr<const Device>> lit::DeviceGroup::getInactiveDevices() const
{
    list<shared_ptr<const Device>> activeDevices;

    for (const auto& iter : aliasMap) {
        const shared_ptr<Device>& devicePtr = iter.second;

        if (devicePtr->isActive() == false) {
            activeDevices.push_back(devicePtr);
        }
    }

    return activeDevices;
}

void lit::DeviceGroup::print(ostream& os) const
{
    Device::printHeader(os);

    // It doesn't matter what map we iterate, they should all have the same values
    for (const auto& device : aliasMap) {
        cout << left << *device.second << '\n';
    }
}
