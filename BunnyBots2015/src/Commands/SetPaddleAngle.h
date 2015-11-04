#ifndef SetPaddleAngle_H
#define SetPaddleAngle_H

#include "../CommandBase.h"
#include "WPILib.h"

class SetPaddleAngle: public CommandBase
{
public:
	SetPaddleAngle(float angle);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	float m_paddleAngle;
};

#endif
