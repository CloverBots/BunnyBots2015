#include "Paddle.h"
#include "../RobotMap.h"

Paddle::Paddle() :
		Subsystem("Paddle")
{
	m_pLeftPaddleMotor = new Talon(RobotMap::PADDLE_LEFT_MOTOR_PORT);
	m_pRightPaddleMotor = new Talon(RobotMap::PADDLE_RIGHT_MOTOR_PORT);
	m_pEncoder = new Encoder(RobotMap::PADDLE_ENCODER_CHANNEL_A, RobotMap::PADDLE_ENCODER_CHANNEL_B,
			false, Encoder::EncodingType::k4X);
	m_pEncoder->SetPIDSourceParameter(Encoder::PIDSourceParameter::kAngle);
	m_pPIDLeftController = new PIDController(m_P, m_I, m_D, m_pEncoder, m_pLeftPaddleMotor);
	m_pPIDRightController = new PIDController(m_P, m_I, m_D, m_pEncoder, m_pRightPaddleMotor);
}

Paddle::~Paddle()
{
	delete m_pEncoder;
	delete m_pPIDLeftController;
	delete m_pLeftPaddleMotor;
	delete m_pRightPaddleMotor;
}

void Paddle::InitDefaultCommand()
{
}

void Paddle::SetAngle(float angle)
{
	m_pPIDLeftController->SetSetpoint(angle);
	m_pPIDRightController->SetSetpoint(angle);
}

