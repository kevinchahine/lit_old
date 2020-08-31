#include "pch.h"

#include "CommandLineHandler.h"
#include "CommandLineParser.h"

#include <iostream>
#include <string>
using std::cin;
using std::cout;

#pragma warning(push, 3)
#include <boost/program_options.hpp>
#pragma warning(pop)

#include "LitServer.h"

namespace lit
{
	namespace cl
	{
		CommandLineHandler::CommandLineHandler(LitServer& server) :
			pLitServer(&server) 
		{}

		void CommandLineHandler::handle(char** argv, int argc)
		{
			// 1.) --- Create options descriptions ---
			boost::program_options::options_description desc("Options");

			desc.add_options()
				("on", "Turns all attached devices on")
				("off", "Turns all attached devices off")
				("set", "Sets color of all devices in rgb format. "
					"Ex: 'lit set 255 0 255', sets all devices to cyan"
					"Ex: 'lit set RED' sets all devices to red")
				("status", "Requests status from each attached device, waits for reply, then prints statuses to screen")
				("discover", "broadcasts discovery message to all devices accross LAN and waits for reply. "
					"Devices that do reply, will be added to discovered devices list")
				("add", "Adds device to attached devices list. Device needs an alias and local IP address")
				("remove", "Removes a device from attached devices list. Device can be selected using either alias or local IP address")
				("rename", "Renames alias of a device. lit rename <old alias>|<ip> <new alias>")
				("list", "Lists discovered devices and attached devices")
				("h,help", "Prints help message");

			// 2.) --- Set options style ---
			namespace style = boost::program_options::command_line_style;

			int git_style =
				style::unix_style |
				style::allow_guessing |
				style::allow_dash_for_short |
				style::allow_long |
				style::short_allow_next;		// allows separation of short options and option values by space instead of =

			// 3.) --- Parse options into a variables map ---
			boost::program_options::variables_map vm;

			boost::program_options::store(
				boost::program_options::command_line_parser(argc, argv).options(desc).style(git_style).run(), vm);

			// 4.) --- If necessary print help message
			if (argc <= 1 || vm.count("help")) {
				cout << "Usage: " << argv[0] << '\n'
					<< desc << '\n';
				cin.get();
				return;
			}

			// 5.) --- Handle options ---
			if (vm.count("on") > 0) {
				//mLitServer
			}
		}
	}
}