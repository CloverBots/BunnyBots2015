#ifndef MoveClawFromJoystick_H
#define MoveClawFromJoystick_H

#include "../CommandBase.h"
#include "WPILib.h"

class MoveClawFromJoystick: public CommandBase
{
public:
	MoveClawFromJoystick();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
