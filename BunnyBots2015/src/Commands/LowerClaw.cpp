#include "LowerClaw.h"
#include "../CommandBase.h"

LowerClaw::LowerClaw()
{
	Requires(CommandBase::pBunnyClaw);
}

// Called just before this Command runs the first time
void LowerClaw::Initialize()
{
	CommandBase::pBunnyClaw->SetLiftSpeed(0.25f);
}

// Called repeatedly when this Command is scheduled to run
void LowerClaw::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool LowerClaw::IsFinished()
{
	return CommandBase::pBunnyClaw->IsLowerLimitReached();
}

// Called once after isFinished returns true
void LowerClaw::End()
{
	CommandBase::pBunnyClaw->SetLiftSpeed(0.0f);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LowerClaw::Interrupted()
{
}
