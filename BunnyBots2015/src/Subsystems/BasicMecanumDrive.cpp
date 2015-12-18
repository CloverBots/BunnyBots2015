#include "BasicMecanumDrive.h"
#include "../Commands/BasicDriveFromJoystick.h"
#include "../RobotMap.h"

BasicMecanumDrive::BasicMecanumDrive() :
		Subsystem("MecanumDrive"), m_xSpeed(0.0f), m_ySpeed(0.0f), m_rotSpeed(0.0f)
{
	m_pFrontLeftMotor = new CANTalon(RobotMap::FRONT_LEFT_MOTOR_PORT);
	m_pRearLeftMotor = new CANTalon(RobotMap::REAR_LEFT_MOTOR_PORT);
	m_pFrontRightMotor = new CANTalon(RobotMap::FRONT_RIGHT_MOTOR_PORT);
	m_pRearRightMotor = new CANTalon(RobotMap::REAR_RIGHT_MOTOR_PORT);

	m_pRobotDrive = new RobotDrive(m_pFrontLeftMotor, m_pRearLeftMotor,
			m_pFrontRightMotor, m_pRearRightMotor);

	m_pRobotDrive->SetSafetyEnabled(false); // TODO: CHANGE. THIS. AS. SOON. AS. POSSIBLE.
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
