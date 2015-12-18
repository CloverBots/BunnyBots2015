#include "AutonomousCommand.h"
#include "PIDDriveFromPresets.h"

AutonomousCommand::AutonomousCommand()
{
	AddSequential(new PIDDriveFromPresets(10.0f, 0.0f, 0.0f));

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
}
