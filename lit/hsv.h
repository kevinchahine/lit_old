
#include "pch.h"

#include <iostream>
#include <iomanip>

#include "IOColor.h"
#include "rgb.h"

namespace lit
{
	using namespace std;

	class hsv
	{
	public:
		hsv() = default;
		hsv(uint8_t hue, uint8_t saturation, uint8_t value) :
			hue(hue),
			saturation(saturation),
			value(value) {}
		hsv(const hsv&) = default;
		virtual ~hsv() noexcept = default;
		hsv& operator=(const hsv&) = default;

		rgb toRGB() const;

		uint8_t hue = 255;
		uint8_t saturation = 255;
		uint8_t value = 255;
	};
}
