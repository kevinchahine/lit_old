#include "pch.h"
#include "Strobe.h"

#include "hsv.h"

lit::scene::Strobe::Strobe()
{
	// Red
	this->push_back(hsv(0, 255, 255).toRGB());
	this->push_back(rgb(0, 0, 0));
	
	// 
	this->push_back(hsv(28, 255, 255).toRGB());
	this->push_back(rgb(0, 0, 0));

	this->push_back(hsv(56, 255, 255).toRGB());
	this->push_back(rgb(0, 0, 0));

	this->push_back(hsv(84, 255, 255).toRGB());
	this->push_back(rgb(0, 0, 0));

	this->push_back(hsv(112, 255, 255).toRGB());
	this->push_back(rgb(0, 0, 0));

	this->push_back(hsv(140, 255, 255).toRGB());
	this->push_back(rgb(0, 0, 0));

	this->push_back(hsv(168, 255, 255).toRGB());
	this->push_back(rgb(0, 0, 0));

	this->push_back(hsv(196, 255, 255).toRGB());
	this->push_back(rgb(0, 0, 0));

	this->push_back(hsv(224, 255, 255).toRGB());
	this->push_back(rgb(0, 0, 0));

	waitTime = chrono::seconds(500);
}
