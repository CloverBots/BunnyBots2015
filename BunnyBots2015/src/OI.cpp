#include "OI.h"

OI::OI()
{
	pStick1 = new Joystick(1);
}

OI::~OI()
{
	delete pStick1;
}

Joystick* OI::getStick1()
{
	return pStick1;
}
