#include "CommandBase.h"
#include "Subsystems/PIDMecanumDrive.h"
#include "Commands/Scheduler.h"

OI* CommandBase::oi = NULL;
//PIDMecanumDrive* CommandBase::pPIDMecanumDrive = NULL;
BasicMecanumDrive* CommandBase::pBasicMecanumDrive = NULL;
Paddle* CommandBase::pPaddle = NULL;
BunnyClaw* CommandBase::pBunnyClaw = NULL;

CommandBase::CommandBase(char const *name) :
		Command(name)
{
}

CommandBase::CommandBase() :
		Command()
{
}

void CommandBase::init()
{
	pPaddle = new Paddle();
	pBasicMecanumDrive = new BasicMecanumDrive();
	pBunnyClaw = new BunnyClaw();

	oi = new OI();
	//pPIDMecanumDrive = new PIDMecanumDrive(); // Uncomment to initialize the subsystem.
}
