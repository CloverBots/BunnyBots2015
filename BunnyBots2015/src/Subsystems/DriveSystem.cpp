#include "DriveSystem.h"
#include "../RobotMap.h"
#include "../Commands/DriveFromJoystick.h"

DriveSystem::DriveSystem() :
		Subsystem("DriveSystem")
{
	pFrontLeftTalon = new Talon(RobotMap::FRONTLEFTMOTOR);
	pFrontRightTalon = new Talon(RobotMap::FRONTRIGHTMOTOR);
	pRearRightTalon = new Talon(RobotMap::REARLEFTMOTOR);
	pRearRightTalon = new Talon(RobotMap::REARRIGHTMOTOR);

	pRobotDrive = new RobotDrive(pFrontLeftTalon, pRearLeftTalon, pFrontRightTalon, pRearRightTalon);
}

void DriveSystem::InitDefaultCommand()
{
	SetDefaultCommand(new DriveFromJoystick());
}

void DriveSystem::drive(float x, float y, float rot)
{
	pRobotDrive->MecanumDrive_Cartesian(x, y, rot, 0);
}
