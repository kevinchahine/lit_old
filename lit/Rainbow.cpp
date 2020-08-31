#include "pch.h"
#include "Rainbow.h"

#include "hsv.h"

lit::scene::Rainbow::Rainbow()
{
	for (int hue = 0; hue < 255; hue++) {
		this->push_back(hsv(hue, 255, 255).toRGB());
	}

	waitTime = chrono::seconds(9000 / 256);
}
