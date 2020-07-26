#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
using std::cout;
using std::cin;
using std::string;

#include <lit/IOColor.h>
#include <lit/rgb.h>
#include <lit/Device.h>
#include <lit/DeviceGroup.h>

#define D(color) lit::setfg(lit::color) << "color" << '\n'

int main(int argc, char** argv)
{
	cout << std::right
		<< lit::setfg(lit::RED) << setfill('=') << setw(12) << '\n'
		<< lit::setfg(lit::GREEN) << "=== LIT ===\n"
		<< lit::setfg(lit::BLUE) << setw(12) << '\n' << setfill(' ');

	cout << std::left;

	shared_ptr<lit::Device> device1Ptr = make_shared<lit::Device>();
	shared_ptr<lit::Device> device2Ptr = make_shared<lit::Device>();
	shared_ptr<lit::Device> device3Ptr = make_shared<lit::Device>();

	device2Ptr->alias() = "Living Room";
	device2Ptr->currentColor().red = 0;
	device2Ptr->lastBadContact() = std::chrono::system_clock::now();
	Sleep(1000);
	device2Ptr->lastGoodContact() = std::chrono::system_clock::now();
	device2Ptr->endpoint() = boost::asio::ip::udp::endpoint(boost::asio::ip::address_v4::from_string("192.168.1.8"), 55'555);

	device3Ptr->alias() = "Party Room";
	device3Ptr->currentColor().green = 0;
	device3Ptr->currentColor().red = 255;
	device3Ptr->currentColor().blue = 255;
	device3Ptr->endpoint() = boost::asio::ip::udp::endpoint(boost::asio::ip::address_v4::from_string("192.168.1.9"), 55'555);

	lit::DeviceGroup group;
	group.insert(device1Ptr);
	group.insert(device2Ptr);
	group.insert(device3Ptr);

	group.print();
	cout << "\n";

	group.changeAlias("dev0", "Kitchen");
	group.changeAlias("dev0", "Bad");

	boost::asio::ip::udp::endpoint newEp(boost::asio::ip::address::from_string("192.168.1.222"), 55'555);
	group.changeEndpoint(device2Ptr->endpoint(), newEp);

	shared_ptr<lit::Device> kitchenPtr = group.pullByAlias("Kitchen");
	if (kitchenPtr != nullptr) {
		kitchenPtr->lastGoodContact() = chrono::system_clock::now();
		group.insert(kitchenPtr);
	}

	group.print();
	cout << '\n';
	
	// --- Set Color ---
	//cout 
	//	<< lit::setcolor(lit::asdf, lit::BLACK) << "asdf" << '\n'
	//	<< lit::setcolor(lit::BLACK) << '\n'
	//	<< lit::setcolor(lit::BLUE) << '\n'
	//	<< lit::setcolor(lit::GREEN) << '\n'
	//	<< lit::setcolor(lit::CYAN) << '\n'
	//	<< lit::setcolor(lit::RED) << '\n'
	//	<< lit::setcolor(lit::MAGENTA) << '\n'
	//	<< lit::setcolor(lit::BROWN) << '\n'
	//	<< lit::setcolor(lit::LIGHTGRAY) << '\n'
	//	<< lit::setcolor(lit::GRAY) << '\n'
	//	<< lit::setcolor(lit::LIGHTBLUE) << '\n'
	//	<< lit::setcolor(lit::LIGHTGREEN) << '\n'
	//	<< lit::setcolor(lit::LIGHTCYAN) << '\n'
	//	<< lit::setcolor(lit::LIGHTRED) << '\n'
	//	<< lit::setcolor(lit::LIGHTMAGENTA) << '\n'
	//	<< lit::setcolor(lit::YELLOW) << '\n'
	//	<< lit::setcolor(lit::WHITE) << '\n'
	
	// --- Set Foreground ---
	//cout
	//	<< lit::setfg(lit::BLACK) << "BLACK" << '\n'
	//	<< lit::setfg(lit::BLUE) << "BLUE" << '\n'
	//	<< lit::setfg(lit::GREEN) << "GREEN" << '\n'
	//	<< lit::setfg(lit::CYAN) << "CYAN" << '\n'
	//	<< lit::setfg(lit::RED) << "RED" << '\n'
	//	<< lit::setfg(lit::MAGENTA) << "MAGENTA" << '\n'
	//	<< lit::setfg(lit::BROWN) << "BROWN" << '\n'
	//	<< lit::setfg(lit::LIGHTGRAY) << "LIGHTGRAY" << '\n'
	//	<< lit::setfg(lit::GRAY) << "GRAY" << '\n'
	//	<< lit::setfg(lit::LIGHTBLUE) << "LIGHTBLUE" << '\n'
	//	<< lit::setfg(lit::LIGHTGREEN) << "LIGHTGREEN" << '\n'
	//	<< lit::setfg(lit::LIGHTCYAN) << "LIGHTCYAN" << '\n'
	//	<< lit::setfg(lit::LIGHTRED) << "LIGHTRED" << '\n'
	//	<< lit::setfg(lit::LIGHTMAGENTA) << "LIGHTMAGENTA" << '\n'
	//	<< lit::setfg(lit::YELLOW) << "YELLOW" << '\n'
	//	<< lit::setfg(lit::WHITE) << "WHITE" << '\n';

	// --- Set Background ---
	//cout
	//	<< lit::setcolor(lit::WHITE, lit::BLACK) 
	//	<< lit::setbg(lit::BLACK) << "BLACK        "<< '\n'
	//	<< lit::setbg(lit::BLUE) << "BLUE        "<< '\n'
	//	<< lit::setbg(lit::GREEN) << "GREEN        "<< '\n'
	//	<< lit::setbg(lit::CYAN) << "CYAN        "<< '\n'
	//	<< lit::setbg(lit::RED) << "RED        "<< '\n'
	//	<< lit::setbg(lit::MAGENTA) << "MAGENTA        "<< '\n'
	//	<< lit::setbg(lit::BROWN) << "BROWN        "<< '\n'
	//	<< lit::setbg(lit::LIGHTGRAY) <<s "LIGHTGRAY        "<< '\n'
	//	<< lit::setbg(lit::GRAY) << "GRAY        "<< '\n'
	//	<< lit::setbg(lit::LIGHTBLUE) << "LIGHTBLUE        "<< '\n'
	//	<< lit::setbg(lit::LIGHTGREEN) << "LIGHTGREEN        "<< '\n'
	//	<< lit::setbg(lit::LIGHTCYAN) << "LIGHTCYAN        "<< '\n'
	//	<< lit::setbg(lit::LIGHTRED) << "LIGHTRED        "<< '\n'
	//	<< lit::setbg(lit::LIGHTMAGENTA) << "LIGHTMAGENTA        "<< '\n'
	//	<< lit::setbg(lit::YELLOW) << "YELLOW        "<< '\n'
	//	<< lit::setbg(lit::WHITE) << "WHITE        "<< '\n';

	cout << lit::rgb(255, 255, 255) << '\n'
		<< lit::rgb(0, 0, 0) << '\n'
		<< lit::rgb(0, 0, 255) << '\n'
		<< lit::rgb(0, 255, 0) << '\n'
		<< lit::rgb(0, 255, 255) << '\n'
		<< lit::rgb(255, 0, 0) << '\n'
		<< lit::rgb(255, 0, 255) << '\n'
		<< lit::rgb(255, 255, 0) << '\n'
		<< lit::rgb(255, 255, 255) << '\n'
		<< '\n';

	cin.get();
	return 0;
}
