#include "pch.h"
#include "attached_device.h"

using namespace std;
using namespace lit;

bool lit::attached_device::isActive() const
{
	return lastBadContact > lastGoodContact;
}
