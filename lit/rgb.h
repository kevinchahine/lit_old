#pragma once

#include "pch.h"

#include <iostream>
#include <iomanip>

#include "iocolor.h"

namespace lit
{
	using namespace std;

	const string COLOR_NAMES[] = {
		"BLACK",		// 0000 0
		"BLUE",			// 0001 1
		"GREEN",		// 0010 2
		"CYAN",			// 0011 3
		"RED",			// 0100 4
		"MAGENTA",		// 0101 5
		"YELLOW",		// 0110 6
		"WHITE",		// 0111 7
		"GRAY",			// 1000 8
		"LIGHTBLUE",	// 1001 9
		"LIGHTGREEN",	// 1010 10
		"LIGHTCYAN",	// 1011 11
		"LIGHTRED",		// 1100 12
		"LIGHTMAGENTA",	// 1101 13
		"BROWN",		// 1110 14
		"WHITE",		// 1111 15
	};

	class rgb
	{
	public:
		rgb() = default;
		rgb(uint8_t red, uint8_t green, uint8_t blue) :
			red(red),
			green(green),
			blue(blue) {}
		rgb(const rgb&) = default;
		virtual ~rgb() noexcept = default;
		rgb& operator=(const rgb&) = default;

		friend ostream& operator<<(ostream& os, const rgb& color)
		{
			auto flags = cout.flags();

			os
				<< left
				<< setw(4) << lit::setfg(RED) << static_cast<int>(color.red)
				<< setw(4) << lit::setfg(GREEN) << static_cast<int>(color.green)
				<< setw(4) << lit::setfg(BLUE) << static_cast<int>(color.blue);

			uint8_t r = ((color.red > 128 ? 1 : 0) << 2);
			uint8_t g = ((color.green > 128 ? 1 : 0) << 1);
			uint8_t b = ((color.blue > 128 ? 1 : 0) << 0);

			cout << static_cast<int>(r) << static_cast<int>(g) << static_cast<int>(b);
			int wordIndex = r | g | b;
			int colorIndex = wordIndex;
			if (wordIndex == (lit::BLACK & 0b0000'0111)) colorIndex = lit::WHITE;

			os << setw(8) 
				<< lit::setfg(colorIndex)
				<< COLOR_NAMES[wordIndex];

			cout.flags(flags);

			return os;
		}

		uint8_t red = 255;
		uint8_t green = 255;
		uint8_t blue = 255;
	};
}