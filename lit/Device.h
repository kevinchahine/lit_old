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
#include "Scene.h"

namespace lit
{
	using namespace std;

	class LIT_API Device
	{
	public: // --------------------------- Public Methods ------------------------

		bool isActive() const;

		static void printHeader(ostream& os = cout);

		// --- Operator Overloads ---

		bool operator<(const Device& rhs) const { return this->m_endpoint < rhs.m_endpoint; }

		bool operator==(const Device& rhs) const { return this->m_endpoint == rhs.m_endpoint; }

		friend ostream& operator<<(ostream& os, const Device& device)
		{
			auto goodTime =
				chrono::system_clock::to_time_t(device.m_lastGoodContact);

			auto badTime =
				chrono::system_clock::to_time_t(device.m_lastBadContact);

			// Get current color 
			int currColorIndex = device.m_currentColor.toConsoleColor();
			if (currColorIndex == lit::BLACK)
				currColorIndex = lit::GRAY;

			os << lit::setfg(currColorIndex)
				<< setw(20) << string("\"" + device.m_aliass + "\"")
				<< setw(20) << device.m_endpoint;

			os << setw(10);
			if (device.isActive()) {
				os << setfg(lit::GREEN) << "ACTIVE";
			} 
			else {
				os << setfg(lit::RED) << "INACTIVE";
			}

			os
				<< setw(20) << goodTime
				<< setw(20) << badTime
				<< setw(20) << device.m_currentColor;;

			return os;
		}

		// --- Accessors ---

		boost::asio::ip::udp::endpoint& endpoint() { return m_endpoint; }
		const boost::asio::ip::udp::endpoint & endpoint() const { return m_endpoint; }

		string& alias() { return m_aliass; }
		const string & alias() const { return m_aliass; }
		
		chrono::system_clock::time_point& lastGoodContact() { return m_lastGoodContact; }
		const chrono::system_clock::time_point & lastGoodContact() const { return m_lastGoodContact; }
		
		chrono::system_clock::time_point& lastBadContact() { return m_lastBadContact; }
		const chrono::system_clock::time_point & lastBadContact() const { return m_lastBadContact; }
		
		unique_ptr<scene> & scenePtr() { return p_scenePtr; }
		const unique_ptr<scene> & scenePtr() const { return p_scenePtr; }

		rgb& currentColor() { return m_currentColor; }
		const rgb& currentColor() const { return m_currentColor; }

	protected: // ------------------------ Protected Fields ----------------------

		boost::asio::ip::udp::endpoint m_endpoint;
		string m_aliass = "";
		chrono::system_clock::time_point m_lastGoodContact;
		chrono::system_clock::time_point m_lastBadContact;
		unique_ptr<scene> p_scenePtr = make_unique<scene>();
		rgb m_currentColor;
	};
}
