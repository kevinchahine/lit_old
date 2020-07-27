#pragma once

#include "pch.h"

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

#include "Scene.h"

namespace lit
{
	using namespace std;

	namespace scene
	{
		class LIT_API Strobe : public SceneBase
		{
		public:
			Strobe();
			Strobe(const Strobe&) = default;
			Strobe(Strobe&&) = default;
			virtual ~Strobe() = default;
			Strobe& operator=(const Strobe&) = default;
			Strobe& operator=(Strobe&&) = default;
		};
	}
}

