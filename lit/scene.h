#pragma once

#include "pch.h"

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <chrono>

#include "lit.h"

#include "rgb.h"

namespace lit
{
	using namespace std;

	namespace scene
	{
		class LIT_API SceneBase : public vector<rgb>
		{
		public: // -------------------- PUBLIC METHODS ------------------------
			
			string serialize() const;

		public:	// -------------------- PUBLIC FIELDS -------------------------
			chrono::seconds waitTime = chrono::seconds(3);
		};
	};
}
