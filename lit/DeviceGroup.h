#pragma once

#include "lit.h"

#include <map>

#include <boost/optional.hpp>

#include "Device.h"

namespace lit
{
	using namespace std;

	using alias_t = string;
	using endpoint_t = boost::asio::ip::udp::endpoint;
	using ip_address_t = boost::asio::ip::address;

	using alias_map_t = map<alias_t, shared_ptr<Device>>;
	using endpoint_map_t = map<endpoint_t, shared_ptr<Device>>;
	using ip_address_map_t = map<ip_address_t, shared_ptr<Device>>;

	class LIT_API DeviceGroup
	{
	public:

		// --- Map Methods ---

		// returns false if there was already a device with matching parameters
		bool insert(shared_ptr<Device>& devicePtr);

		void erase(shared_ptr<Device>& devicePtr);

		void erase(const Device& device);

		// --- Accessors ---

		shared_ptr<Device> pullByAlias(const alias_t& alias);

		shared_ptr<Device> pullByEndpoint(const endpoint_t& ep);

		shared_ptr<Device> pullByIpAddress(const ip_address_t& ip);

		boost::optional<const Device&> getByAlias(const alias_t& alias) const;

		boost::optional<const Device&> getByEndpoint(const endpoint_t& ep) const;

		boost::optional<const Device&> getByIpAddress(const ip_address_t& ip) const;

		// --- Modifiers ---

		void changeAlias(const alias_t& currAlias, const alias_t& newAlias);

		void changeEndpoint(const endpoint_t& currEp, const endpoint_t& newEp);

		void changeIpAddress(const ip_address_t& currIp, const ip_address_t& newIp);

		// --- Filters ---

		list<shared_ptr<const Device>> getActiveDevices() const;

		list<shared_ptr<const Device>> getInactiveDevices() const;

		// --- Output ---

		void print(ostream& os = cout) const;

	protected:
		alias_map_t aliasMap;
		endpoint_map_t endpointMap;
		ip_address_map_t ipAddressMap;
	};
}