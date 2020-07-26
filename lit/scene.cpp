#include "pch.h"
#include "Scene.h"

using namespace std;

string lit::scene::serialize() const
{
	stringstream packet;

	packet << waitTime;

	for_each(begin(), end(), [&packet](const rgb& color) {
		packet << color.red << color.green << color.blue;
		});

	return packet.str();
}
