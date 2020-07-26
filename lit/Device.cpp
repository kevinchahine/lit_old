#include "pch.h"
#include "Device.h"

using namespace std;
using namespace lit;

bool lit::Device::isActive() const
{
	return m_lastGoodContact > m_lastBadContact;
}

void lit::Device::printHeader(ostream& os)
{
	os << lit::saveFlags() << left
		<< setw(20) << "Alias"
		<< setw(20) << "Endpoint"
		<< setw(10) << "State"
		<< setw(20) << "Last Good Contact"
		<< setw(20) << "Last Bad Contact"
		<< setw(20) << "Current Color"
		<< '\n'
		<< lit::restoreFlags();
}
