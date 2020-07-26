#pragma once

#include "lit.h"

#include <boost/bimap.hpp>

#include "Device.h"

namespace lit
{
	using namespace std;

	using device = int;
	using endpoint = int;

	using DeviceMap = boost::bimaps::bimap<
		boost::bimaps::set_of<boost::bimaps::tagged<Device, device >>,
		boost::bimaps::set_of<boost::bimaps::tagged<string, endpoint>>
	>;

	//class LIT_API DeviceGroup : DeviceMap
	//{
	//public:
	//	const attached_device & getByAlias(const string& alias) const;

	//	const attached_device & getByEndpoint(const boost::asio::ip::udp::endpoint& ep) const;

	//	const attached_device & getByIpAddress(const boost::asio::ip::address_v4& ip) const;

	//	//pair<DeviceMap::iterator, DeviceMap::iterator> getByStatus(const status& status) const;

	//};

}