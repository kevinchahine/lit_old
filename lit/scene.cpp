#include "pch.h"
#include "Scene.h"

using namespace std;

string lit::scene::SceneBase::serialize() const
{
	stringstream packet;

	packet << waitTime;

	for_each(begin(), end(), [&packet](const rgb& color) {
		packet << color.red << color.green << color.blue;
		});

	return packet.str();
}
