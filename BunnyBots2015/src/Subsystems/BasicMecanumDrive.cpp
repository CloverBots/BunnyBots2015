#include "BasicMecanumDrive.h"
#include "../Commands/BasicDriveFromJoystick.h"
#include "../RobotMap.h"

BasicMecanumDrive::BasicMecanumDrive() :
		Subsystem("MecanumDrive"), m_xSpeed(0.0f), m_ySpeed(0.0f), m_rotSpeed(0.0f)
{
	m_pFrontLeftMotor = new Talon(RobotMap::FRONT_LEFT_MOTOR_PORT);
	m_pRearLeftMotor = new Talon(RobotMap::REAR_LEFT_MOTOR_PORT);
	m_pFrontRightMotor = new Talon(RobotMap::FRONT_RIGHT_MOTOR_PORT);
	m_pRearRightMotor = new Talon(RobotMap::REAR_RIGHT_MOTOR_PORT);

	m_pRobotDrive = new RobotDrive(m_pFrontLeftMotor, m_pRearLeftMotor,
			m_pFrontRightMotor, m_pRearRightMotor);
	m_pRobotDrive->SetExpiration(0.25f);
}

BasicMecanumDrive::~BasicMecanumDrive()
{
	delete m_pRobotDrive;
	delete m_pFrontLeftMotor;
	delete m_pRearLeftMotor;
	delete m_pFrontRightMotor;
	delete m_pRearRightMotor;
}

void BasicMecanumDrive::InitDefaultCommand()
{
	SetDefaultCommand(new BasicDriveFromJoystick());
}

void BasicMecanumDrive::Drive(float xSpeed, float ySpeed, float rotSpeed)
{
	m_pRobotDrive->MecanumDrive_Cartesian(
			m_xSpeed = xSpeed,
			m_ySpeed = ySpeed,
			m_rotSpeed = rotSpeed,
			0.0f);
}

void BasicMecanumDrive::SetSafetyEnabled(bool enabled)
{
	m_pRobotDrive->SetSafetyEnabled(enabled);
}

float BasicMecanumDrive::GetXSpeed()
{
	return m_xSpeed;
}

float BasicMecanumDrive::GetYSpeed()
{
	return m_ySpeed;
}

float BasicMecanumDrive::GetRotSpeed()
{
	return m_rotSpeed;
}
