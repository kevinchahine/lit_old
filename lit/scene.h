#pragma once

#include "pch.h"

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

#include "lit.h"

#include "rgb.h"

namespace lit
{
	using namespace std;

	class LIT_API scene : public vector<rgb>
	{
	public:
		string serialize() const;

		uint16_t waitTime;
	};
}
