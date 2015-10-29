#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:

	Joystick* pStick1;
	Joystick* pStick2;

	JoystickButton* pLeftBumper;
	JoystickButton* pRightBumper;

public:
	OI();
	~OI();

	Joystick* getStick1();
	Joystick* getStick2();
};

#endif
