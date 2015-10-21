#include "DriveFromJoystick.h"

DriveFromJoystick::DriveFromJoystick()
{
	Requires(pPIDMecanumDrive);
}

// Called just before this Command runs the first time
void DriveFromJoystick::Initialize()
{
	pPIDMecanumDrive->Drive(0, 0, 0);
}

// Called repeatedly when this Command is scheduled to run
void DriveFromJoystick::Execute()
{
	pPIDMecanumDrive->Drive(oi->getStick1()->GetRawAxis(0),
			oi->getStick1()->GetRawAxis(1),
			oi->getStick1()->GetRawAxis(4));
}

// Make this return true when this Command no longer needs to run execute()
bool DriveFromJoystick::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveFromJoystick::End()
{
	pPIDMecanumDrive->Drive(0, 0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveFromJoystick::Interrupted()
{
}
