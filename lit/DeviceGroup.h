#pragma once

#include "lit.h"

#include <map>

#pragma warning(push, 3)
#include <boost/optional.hpp>
#pragma warning(pop)

#include "Device.h"

namespace lit
{
	using namespace std;

	using alias_t = string;
	using endpoint_t = boost::asio::ip::udp::endpoint;
	using ip_address_t = boost::asio::ip::address;

	namespace devices
	{
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

			// Removes and returns device with matching alias
			shared_ptr<Device> pullByAlias(const alias_t& alias);

			// Removes and returns device with matching endpoint
			shared_ptr<Device> pullByEndpoint(const endpoint_t& ep);

			// Removes and returns device with matching ip address
			shared_ptr<Device> pullByIpAddress(const ip_address_t& ip);

			boost::optional<const Device&> getByAlias(const alias_t& alias) const;

			boost::optional<const Device&> getByEndpoint(const endpoint_t& ep) const;

			boost::optional<const Device&> getByIpAddress(const ip_address_t& ip) const;

			//ip_address_map_t::iterator begin();
			//
			//const ip_address_map_t::const_iterator begin() const;
			//
			//ip_address_map_t::iterator end();
			//
			//const ip_address_map_t::const_iterator end() const;

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
}