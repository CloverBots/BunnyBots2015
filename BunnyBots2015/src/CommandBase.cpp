#include "CommandBase.h"
#include "Subsystems/PIDMecanumDrive.h"
#include "Commands/Scheduler.h"

PIDMecanumDrive* CommandBase::pPIDMecanumDrive = NULL;
OI* CommandBase::oi = NULL;
Paddle* CommandBase::pPaddle = NULL;

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
	oi = new OI();
	pPIDMecanumDrive = new PIDMecanumDrive();
	pPaddle = new Paddle();
}
