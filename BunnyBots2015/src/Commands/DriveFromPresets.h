#ifndef DriveFromPresets_H
#define DriveFromPresets_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveFromPresets: public CommandBase
{
private:
	float m_x, m_y, m_rotation;
public:
	DriveFromPresets(float xFeet, float yFeet, float rotation);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
