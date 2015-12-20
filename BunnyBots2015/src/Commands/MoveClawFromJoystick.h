#ifndef MoveClawFromJoystick_H
#define MoveClawFromJoystick_H

#include "../CommandBase.h"
#include "WPILib.h"

class MoveClawFromJoystick: public CommandBase
{
private:

	const float m_lowerSpeed = 0.25f;
	const float m_liftSpeed = -0.5;

public:
	MoveClawFromJoystick();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
