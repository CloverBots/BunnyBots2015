#ifndef DriveSystem_H
#define DriveSystem_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveSystem: public Subsystem
{
private:
	Talon frontRightTalon;
	Talon frontLeftTalon;
	Talon rearRightTalon;
	Talon rearLeftTalon;

	RobotDrive robotDrive;
public:
	DriveSystem();
	void InitDefaultCommand();
	void drive(float x, float y, float rot);
};

#endif
