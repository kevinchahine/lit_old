#pragma once

#include "pch.h"

#include <iostream>
#include <iomanip>

#include "IOColor.h"

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
			os
				<< left << lit::saveFlags()
				<< setw(4) << lit::setfg(RED) << static_cast<int>(color.red)
				<< setw(4) << lit::setfg(GREEN) << static_cast<int>(color.green)
				<< setw(4) << lit::setfg(BLUE) << static_cast<int>(color.blue);

			int colorIndex = color.toConsoleColor();
			int showingColorIndex = colorIndex;			// set this to white incase the color index is black
			if (colorIndex == lit::BLACK) showingColorIndex = lit::WHITE;

			os << setw(8) 
				<< lit::setfg(showingColorIndex)
				<< COLOR_NAMES[colorIndex]
				<< lit::restoreFlags();

			return os;
		}

		// Returns the console color index.
		// Ex:	lit::rgb color;
		//		int consoleColor = color.toConsoleColor();
		//		cout << lit::setfg(consoleColor) << "Hehehe";	// Prints foreground in a color matching color;
		// Warning: If color may be black and may not show up on console
		int toConsoleColor() const
		{
			uint8_t r = ((red > 128 ? 1 : 0) << 2);
			uint8_t g = ((green > 128 ? 1 : 0) << 1);
			uint8_t b = ((blue > 128 ? 1 : 0) << 0);

			///cout << static_cast<int>(r) << static_cast<int>(g) << static_cast<int>(b);
			int wordIndex = r | g | b;
			return wordIndex;
		}

		uint8_t red = 255;
		uint8_t green = 255;
		uint8_t blue = 255;
	};
}