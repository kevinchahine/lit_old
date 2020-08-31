#pragma once

#include <chrono>

#include "AttachedDevices.h"
#include "DiscoveredDevices.h"

namespace lit
{
	namespace network
	{
		class NetworkInterface
		{
		public:
			// 1.) Broadcasts discovery message to devices on LAN.
			// 2.) Waits for a reply
			// 3.) Adds replies as devices in discovered devices list.
			void discover(std::chrono::seconds waitTime = std::chrono::seconds(3));

			// 1.) Sends command to all attached devices to turn on
			// 2.) Waits for status reply
			// 3.) Updates attached devices list with new status
			void setOn(std::chrono::seconds waitTime = std::chrono::seconds(3));

			// 1.) Sends command to attached devices to turn off
			// 2.) Waits for status reply
			// 3.) Updates attached devices list with new status
			void setOff(std::chrono::seconds waitTime = std::chrono::seconds(3));

		private:
			lit::devices::DiscoveredDevices mDiscovered;

			lit::devices::AttachedDevices mAttached;
		};
	}
}
