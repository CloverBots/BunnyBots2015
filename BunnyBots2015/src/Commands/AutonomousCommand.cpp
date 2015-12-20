#include "AutonomousCommand.h"
#include "Delay.h"
#include "CommandBase.h"
#include "LowerClaw.h"
#include "RaiseClaw.h"
#include "SetClawGrabSpeed.h"
#include "SetPaddleAngle.h"
#include "DriveFromPresets.h"

AutonomousCommand::AutonomousCommand()
{
	Requires(CommandBase::pBasicMecanumDrive);
	Requires(CommandBase::pPaddle);
	Requires(CommandBase::pBunnyClaw);

	AddSequential(new LowerClaw());
	AddSequential(new SetClawGrabSpeed(-1.0f));
	AddSequential(new Delay(1.0));
	AddSequential(new RaiseClaw());
	AddSequential(new DriveFromPresets(0.0f, -0.5f, 0.0f));
	AddSequential(new Delay(1.0));
	AddSequential(new SetPaddleAngle(0.35f));
	AddSequential(new Delay(0.5));
	AddSequential(new DriveFromPresets(0.0f, 0.0f, -1.0f));
	AddSequential(new Delay(0.05));
	AddSequential(new DriveFromPresets(0.0f, -1.0f, 0.0f));
	AddSequential(new Delay(1.75));
	AddSequential(new DriveFromPresets(0.0f, 0.0f, 0.0f));
}
