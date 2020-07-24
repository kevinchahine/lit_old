#pragma once

#include "pch.h"

#include <iostream>
#include <iomanip>
#include <iterator>
#include <memory>
#include <string>
#include <vector>
#include <chrono>
#include <memory>

#include <boost/asio.hpp>

#include "lit.h"
#include "scene.h"

namespace lit
{
	using namespace std;

	class LIT_API attached_device
	{
	public:

		bool isActive() const;

		friend ostream& operator<<(ostream& os, const attached_device& device)
		{
			ostream_iterator<string> outIter(os, "\t");
			copy(device.aliass.begin(), device.aliass.end(), outIter);

			os << '\n';

			return os;
		}

	protected:
		boost::asio::ip::udp::endpoint endpoint;
		vector<string> aliass;
		chrono::system_clock::time_point lastGoodContact;
		chrono::system_clock::time_point lastBadContact;
		unique_ptr<scene> scenePtr = make_unique<scene>();
	};
}
