#pragma once

#include "Scene.h"

namespace lit
{
	using namespace std;

	namespace scene
	{
		class LIT_API Rainbow : public SceneBase
		{
		public:
			Rainbow();
			Rainbow(const Rainbow&) = default;
			Rainbow(Rainbow&&) = default;
			virtual ~Rainbow() = default;
			Rainbow& operator=(const Rainbow&) = default;
			Rainbow& operator=(Rainbow&&) = default;
		};
	}
}
