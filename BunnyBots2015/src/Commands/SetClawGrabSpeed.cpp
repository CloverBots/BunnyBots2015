#include "SetClawGrabSpeed.h"
#include "CommandBase.h"

SetClawGrabSpeed::SetClawGrabSpeed(float speed)
: m_speed(speed)
{
	Requires(CommandBase::pBunnyClaw);
}

// Called just before this Command runs the first time
void SetClawGrabSpeed::Initialize()
{
	CommandBase::pBunnyClaw->SetGrabSpeed(m_speed);
}

// Called repeatedly when this Command is scheduled to run
void SetClawGrabSpeed::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool SetClawGrabSpeed::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void SetClawGrabSpeed::End()
{
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetClawGrabSpeed::Interrupted()
{
}
