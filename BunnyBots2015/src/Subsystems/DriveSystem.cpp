#include "DriveSystem.h"
#include "../RobotMap.h"
#include "../Commands/DriveFromJoystick.h"

DriveSystem::DriveSystem() :
		Subsystem("DriveSystem")
{
	pFrontLeftTalon = new Talon(RobotMap::FRONTLEFTMOTOR);
	pFrontRightTalon = new Talon(RobotMap::FRONTRIGHTMOTOR);
	pRearLeftTalon = new Talon(RobotMap::REARLEFTMOTOR);
	pRearRightTalon = new Talon(RobotMap::REARRIGHTMOTOR);

	pRobotDrive = new RobotDrive(pFrontLeftTalon, pRearLeftTalon, pFrontRightTalon, pRearRightTalon);
}

DriveSystem::~DriveSystem()
{
	delete pFrontLeftTalon;
	delete pFrontRightTalon;
	delete pRearLeftTalon;
	delete pRearRightTalon;

	delete pRobotDrive;
}

void DriveSystem::InitDefaultCommand()
{
	SetDefaultCommand(new DriveFromJoystick());
}

void DriveSystem::Drive(float x, float y, float rot)
{
	pRobotDrive->MecanumDrive_Cartesian(x, y, rot, 0);
}
