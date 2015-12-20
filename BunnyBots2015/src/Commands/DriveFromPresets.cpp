#include "DriveFromPresets.h"
#include "../CommandBase.h"

DriveFromPresets::DriveFromPresets(float xSpeed, float ySpeed, float rotSpeed)
: m_xSpeed(xSpeed), m_ySpeed(ySpeed), m_rotSpeed(rotSpeed)
{
	Requires(CommandBase::pBasicMecanumDrive);
}

// Called just before this Command runs the first time
void DriveFromPresets::Initialize()
{
	CommandBase::pBasicMecanumDrive->Drive(m_xSpeed, m_ySpeed, m_rotSpeed);
}

// Called repeatedly when this Command is scheduled to run
void DriveFromPresets::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool DriveFromPresets::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void DriveFromPresets::End()
{
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveFromPresets::Interrupted()
{
}
