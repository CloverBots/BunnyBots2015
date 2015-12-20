#ifndef BasicDriveFromJoystick_H
#define BasicDriveFromJoystick_H

#include "../CommandBase.h"
#include "WPILib.h"

class BasicDriveFromJoystick: public CommandBase
{
private:

	const float m_slowSpeed = 0.5f;
	const float m_maxSpeed = 1.0f;

public:
	BasicDriveFromJoystick();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
