#include "../Commands/PIDDriveFromJoystick.h"
#include "../CommandBase.h"

PIDDriveFromJoystick::PIDDriveFromJoystick()
	: CommandBase("PIDDriveFromJoystick")
{
	//Requires(CommandBase::pPIDMecanumDrive);
}

// Called just before this Command runs the first time
void PIDDriveFromJoystick::Initialize()
{
	//CommandBase::pPIDMecanumDrive->DriveSetSpeed(0, 0, 0);
}

// Called repeatedly when this Command is scheduled to run
void PIDDriveFromJoystick::Execute()
{
	//CommandBase::pPIDMecanumDrive->DriveSetSpeed(oi->getStick1()->GetRawAxis(0),
			//oi->getStick1()->GetRawAxis(1),
			//oi->getStick1()->GetRawAxis(4));
}

// Make this return true when this Command no longer needs to run execute()
bool PIDDriveFromJoystick::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void PIDDriveFromJoystick::End()
{
	//CommandBase::pPIDMecanumDrive->DriveSetSpeed(0, 0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PIDDriveFromJoystick::Interrupted()
{
}
