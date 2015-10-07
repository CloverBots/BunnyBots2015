#include "DriveSystem.h"
#include "../RobotMap.h"
#include "../DriveFromJoystick.h"

DriveSystem::DriveSystem() :
		Subsystem("ExampleSubsystem")
{
	frontLeftTalon = Talon(RobotMap::FRONTLEFTMOTOR);
	frontRightTalon = Talon(RobotMap::FRONTRIGHTMOTOR);
	rearRightTalon = Talon(RobotMap::REARLEFTMOTOR);
	rearRightTalon = Talon(RobotMap::REARRIGHTMOTOR);

	robotDrive = RobotDrive(frontLeftTalon, rearLeftTalon, frontRightTalon, rearRightTalon);
}

void DriveSystem::InitDefaultCommand()
{
	SetDefaultCommand(new DriveFromJoystick());
}

void DriveSystem::drive(float x, float y, float rot)
{
	robotDrive.MecanumDrive_Cartesian(x, y, rot, 0f);
}
