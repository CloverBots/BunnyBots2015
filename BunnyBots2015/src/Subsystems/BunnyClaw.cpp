#include "BunnyClaw.h"
#include "../RobotMap.h"
#include "../Commands/MoveClawFromJoystick.h"

BunnyClaw::BunnyClaw() :
		Subsystem("BunnyClaw")
{
	m_pClawTalon = new Talon(RobotMap::CLAW_LIFTER_PORT);
	m_pClawVictor = new Victor(RobotMap::CLAW_GRABBER_PORT);
}

BunnyClaw::~BunnyClaw()
{
	delete m_pClawTalon;
	delete m_pClawVictor;
}

void BunnyClaw::InitDefaultCommand()
{
	SetDefaultCommand(new MoveClawFromJoystick());
}

void BunnyClaw::SetLiftSpeed(float speed)
{
	m_pClawTalon->SetSpeed(speed);
}

void BunnyClaw::SetGrabSpeed(float speed)
{
	m_pClawVictor->SetSpeed(speed);
}
