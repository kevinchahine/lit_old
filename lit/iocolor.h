#pragma once

#include "pch.h"
#include <iostream>
#include <Windows.h>

namespace lit
{
	static const uint8_t BLACK = 0;
	static const uint8_t BLUE = 1;
	static const uint8_t GREEN = 2;
	static const uint8_t CYAN = 3;
	static const uint8_t RED = 4;
	static const uint8_t MAGENTA = 5;
	static const uint8_t YELLOW = 6;
	static const uint8_t LIGHTGRAY = 7;
	static const uint8_t GRAY = 8;
	static const uint8_t LIGHTBLUE = 9;
	static const uint8_t LIGHTGREEN = 10;
	static const uint8_t LIGHTCYAN = 11;
	static const uint8_t LIGHTRED = 12;
	static const uint8_t LIGHTMAGENTA = 13;
	static const uint8_t BROWN = 14;
	static const uint8_t WHITE = 15;

	inline uint8_t calcColor(uint8_t foreground, uint8_t background)
	{
		return ((foreground & 0b0000'1111) | (background << 4));
	}

	inline uint8_t calcForeground(uint8_t color)
	{
		return (color & 0b0000'1111);
	}

	inline uint8_t calcBackground(uint8_t color)
	{
		return (color >> 4);
	}

	static WORD currColor = calcColor(WHITE, BLACK);
	static HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	static CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

	class setcolor
	{
	public:
		setcolor(WORD color) :
			newColor(color) {}

		setcolor(uint8_t foreground, uint8_t background) :
			newColor(calcColor(foreground, background)) {}

		friend std::ostream& operator<<(std::ostream& os, const setcolor& rhs)
		{
			if (currColor != rhs.newColor) {
				SetConsoleTextAttribute(h, rhs.newColor);
				currColor = rhs.newColor;
			}

			return os;
		}

	protected:
		WORD newColor;
	};
	
	class setfg : public setcolor
	{
	public:
		setfg(uint8_t fgColor) : setcolor(fgColor, calcBackground(currColor)) {}
	};

	class setbg : public setcolor
	{
	public:
		setbg(uint8_t bgColor) : setcolor(calcForeground(currColor), bgColor) {}
	};
}
