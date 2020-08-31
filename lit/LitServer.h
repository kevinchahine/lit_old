#pragma once

#include "CommandLineParser.h"
#include "AttachedDevices.h"
#include "DiscoveredDevices.h"
#include "NetworkInterface.h"
#include "CommandLineHandler.h"

namespace lit
{
	namespace server
	{
		class LitServer
		{
		public:
			void parseCommandLine(char** argv, int argc);

			//void parseXML()

			void turnOnAttachedDevices();

			void turnOffAttachedDevices();

			void attachDevice();

			void discoverDevices();

		private:
			devices::AttachedDevices attached;

			devices::DiscoveredDevices discovered;

			network::NetworkInterface netInterface;

			cl::CommandLineHandler handler;
		};
	}
}
