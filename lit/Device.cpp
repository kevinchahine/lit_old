#include "pch.h"
#include "Device.h"

using namespace std;
using namespace lit;

namespace lit {
	namespace devices
	{
		bool Device::isActive() const
		{
			return m_lastGoodContact > m_lastBadContact;
		}

		void Device::printHeader(ostream& os)
		{
			os << lit::saveFlags() << left
				<< setw(20) << "Alias"
				<< setw(20) << "Endpoint"
				<< setw(10) << "State"
				<< setw(20) << "Last Good Contact"
				<< setw(20) << "Last Bad Contact"
				<< setw(20) << "Current Color"
				<< '\n'
				<< restoreFlags();
		}
	}
}