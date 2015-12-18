#include "MoveClawFromJoystick.h"

MoveClawFromJoystick::MoveClawFromJoystick()
{
	Requires(CommandBase::pBunnyClaw);
}

// Called just before this Command runs the first time
void MoveClawFromJoystick::Initialize()
{
}

// Called repeatedly when this Command is scheduled to run
void MoveClawFromJoystick::Execute()
{
	CommandBase::pBunnyClaw->SetLiftSpeed(
			std::fmax(std::fmin(CommandBase::oi->GetStick2()->GetRawAxis(1),
					CommandBase::pBunnyClaw->IsLowerLimitReached() ? 0 : -1),
					CommandBase::pBunnyClaw->IsUpperLimitReached() ? 0 : 1)
	);

	CommandBase::pBunnyClaw->SetGrabSpeed(CommandBase::oi->GetStick2()->GetRawAxis(5));
}

// Make this return true when this Command no longer needs to run execute()
bool MoveClawFromJoystick::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void MoveClawFromJoystick::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveClawFromJoystick::Interrupted()
{
}
