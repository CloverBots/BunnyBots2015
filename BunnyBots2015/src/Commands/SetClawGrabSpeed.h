#ifndef SetClawGrabSpeed_H
#define SetClawGrabSpeed_H

#include "../CommandBase.h"
#include "WPILib.h"

class SetClawGrabSpeed: public CommandBase
{
private:
	float m_speed;

public:
	SetClawGrabSpeed(float speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
