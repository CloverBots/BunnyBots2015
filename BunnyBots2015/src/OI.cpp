#include "OI.h"
#include "Commands/SetPaddleAngle.h"

OI::OI()
{
	pStick1 = new Joystick(0);
	pStick2 = new Joystick(1);

	pLeftBumper = new JoystickButton(pStick2, 5);
	pRightBumper = new JoystickButton(pStick2, 6);

	pLeftBumper->WhenPressed(new SetPaddleAngle(0.35f));
	pRightBumper->WhenPressed(new SetPaddleAngle(0.0f));
}

OI::~OI()
{
	delete pStick1;
	delete pStick2;
	delete pLeftBumper;
	delete pRightBumper;
}

Joystick* OI::GetStick1()
{
	return pStick1;
}

Joystick* OI::GetStick2()
{
	return pStick2;
}
