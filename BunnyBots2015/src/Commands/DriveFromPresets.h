#ifndef DriveFromPresets_H
#define DriveFromPresets_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveFromPresets: public CommandBase
{
private:
	float m_xSpeed, m_ySpeed, m_rotSpeed;

public:
	DriveFromPresets(float xSpeed, float ySpeed, float rotSpeed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
