#ifndef DriveFromJoystick_H
#define DriveFromJoystick_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveFromJoystick: public CommandBase
{
public:
	DriveFromJoystick();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
