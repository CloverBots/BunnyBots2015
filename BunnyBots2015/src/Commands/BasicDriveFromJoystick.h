#ifndef BasicDriveFromJoystick_H
#define BasicDriveFromJoystick_H

#include "../CommandBase.h"
#include "WPILib.h"

class BasicDriveFromJoystick: public CommandBase
{
public:
	BasicDriveFromJoystick();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
