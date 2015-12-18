#ifndef DriveFromPresets_H
#define DriveFromPresets_H

#include "../CommandBase.h"
#include "WPILib.h"

class PIDDriveFromPresets: public CommandBase
{
private:
	float m_x, m_y, m_rotation;
public:
	PIDDriveFromPresets(float xFeet, float yFeet, float rotation);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
