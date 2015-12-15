#ifndef DriveFromJoystick_H
#define DriveFromJoystick_H

#include "../CommandBase.h"
#include "WPILib.h"

class PIDDriveFromJoystick: public CommandBase
{
public:
	PIDDriveFromJoystick();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
