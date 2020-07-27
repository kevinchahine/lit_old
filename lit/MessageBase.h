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

	class MessageBase
	{
	public:
		string serialize() const;

		void parse(const string& str);

	public:
		scene::SceneBase m_scene;
	};
}
