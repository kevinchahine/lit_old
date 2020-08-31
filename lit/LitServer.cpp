#include "pch.h"
#include "LitServer.h"

#include <algorithm>
#include <iterator>

using namespace std;

namespace lit
{
	namespace server
	{
		void LitServer::parseCommandLine(char** argv, int argc)
		{
			handler.handle(argv, argc);
		}

		void LitServer::turnOnAttachedDevices()
		{
			//for_each(attached.begin(), attached.end(), sendOn)
		}

		void LitServer::turnOffAttachedDevices()
		{
			//for_each(attached.begin(), attached.end(), sendOff)
		}

		void LitServer::attachDevice()
		{

		}

		void LitServer::discoverDevices()
		{
		}
	}
}
