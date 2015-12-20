#include "BasicDriveFromJoystick.h"
#include "../CommandBase.h"
#include <iostream>

BasicDriveFromJoystick::BasicDriveFromJoystick()
{
	Requires(CommandBase::pBasicMecanumDrive);
}

// Called just before this Command runs the first time
void BasicDriveFromJoystick::Initialize()
{
}

// Called repeatedly when this Command is scheduled to run
void BasicDriveFromJoystick::Execute()
{
	float speed = oi->GetStick1()->GetRawButton(6) ? m_slowSpeed : m_maxSpeed;

	CommandBase::pBasicMecanumDrive->Drive(
			oi->GetStick1()->GetRawAxis(0) * speed,
			oi->GetStick1()->GetRawAxis(1) * speed,
			oi->GetStick1()->GetRawAxis(4) * speed);
}

// Make this return true when this Command no longer needs to run execute()
bool BasicDriveFromJoystick::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void BasicDriveFromJoystick::End()
{
	CommandBase::pBasicMecanumDrive->Drive(0.0f, 0.0f, 0.0f);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BasicDriveFromJoystick::Interrupted()
{
}
