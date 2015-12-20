#include "Paddle.h"
#include "../RobotMap.h"

Paddle::Paddle() :
		Subsystem("Paddle")
{
	m_pEncoder = new Encoder(RobotMap::PADDLE_ENCODER_CHANNEL_A, RobotMap::PADDLE_ENCODER_CHANNEL_B,
			false, Encoder::EncodingType::k4X);
	m_pEncoder->SetPIDSourceParameter(Encoder::PIDSourceParameter::kDistance);
	m_pEncoder->SetDistancePerPulse(0.005);
	m_pPIDOutput = new PaddlePIDOutput(RobotMap::PADDLE_LEFT_MOTOR_PORT, RobotMap::PADDLE_RIGHT_MOTOR_PORT,
			false, true);
	m_pPIDController = new PIDController(m_P, m_I, m_D, m_pEncoder, m_pPIDOutput);
	m_pPIDController->SetContinuous(false);
}

Paddle::~Paddle()
{
	delete m_pEncoder;
	delete m_pPIDController;
	delete m_pPIDOutput;
}

void Paddle::InitDefaultCommand()
{
}

void Paddle::SetEnabled(bool enabled)
{
	if (enabled)
	{
		m_pEncoder->Reset();
		m_pPIDController->Enable();
		m_pPIDController->SetSetpoint(0.0f);
	}
	else
	{
		m_pPIDController->Reset();
	}
}

float Paddle::GetRate()
{
	return m_pEncoder->GetRate();
}

void Paddle::SetAngle(float angle)
{
	m_pPIDController->SetSetpoint(angle);
}

