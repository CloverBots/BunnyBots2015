#include "RaiseClaw.h"
#include "../CommandBase.h"

RaiseClaw::RaiseClaw()
{
	Requires(CommandBase::pBunnyClaw);
}

// Called just before this Command runs the first time
void RaiseClaw::Initialize()
{
	CommandBase::pBunnyClaw->SetLiftSpeed(-0.5f);
}

// Called repeatedly when this Command is scheduled to run
void RaiseClaw::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool RaiseClaw::IsFinished()
{
	return CommandBase::pBunnyClaw->IsUpperLimitReached();
}

// Called once after isFinished returns true
void RaiseClaw::End()
{
	CommandBase::pBunnyClaw->SetLiftSpeed(0.0f);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RaiseClaw::Interrupted()
{
}
