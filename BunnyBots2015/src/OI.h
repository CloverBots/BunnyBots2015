#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:

	Joystick* pStick1;

public:
	OI();
	~OI();

	Joystick* getStick1();
};

#endif
