#ifndef DriveSystem_H
#define DriveSystem_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveSystem: public Subsystem
{
private:
	Talon* pFrontRightTalon;
	Talon* pFrontLeftTalon;
	Talon* pRearRightTalon;
	Talon* pRearLeftTalon;

	RobotDrive* pRobotDrive;
public:
	DriveSystem();
	void InitDefaultCommand();
	void drive(float x, float y, float rot);
};

#endif
