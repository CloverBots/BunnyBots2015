#include "BunnyClaw.h"
#include "../RobotMap.h"
#include "../Commands/MoveClawFromJoystick.h"

BunnyClaw::BunnyClaw() :
		Subsystem("BunnyClaw")
{
	m_pClawTalon = new Talon(RobotMap::CLAW_LIFTER_PORT);
	m_pClawVictor = new Victor(RobotMap::CLAW_GRABBER_PORT);
	m_pLowerLimitSwitch = new DigitalInput(RobotMap::CLAW_LIMIT_SWITCH_LOWER);
	m_pUpperLimitSwitch = new DigitalInput(RobotMap::CLAW_LIMIT_SWITCH_UPPER);
}

BunnyClaw::~BunnyClaw()
{
	delete m_pClawTalon;
	delete m_pClawVictor;
	delete m_pLowerLimitSwitch;
	delete m_pUpperLimitSwitch;
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

bool BunnyClaw::IsLowerLimitReached()
{
	return !m_pLowerLimitSwitch->Get();
}

bool BunnyClaw::IsUpperLimitReached()
{
	return !m_pUpperLimitSwitch->Get();
}
