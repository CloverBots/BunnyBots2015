#include "Paddle.h"
#include "../RobotMap.h"

Paddle::Paddle() :
		Subsystem("ExampleSubsystem")
{
	m_pPaddleMotor = new Talon(RobotMap::PADDLE_MOTOR_PORT);
	m_pEncoder = new Encoder(RobotMap::PADDLE_CHANNEL_A, RobotMap::PADDLE_CHANNEL_B, false, Encoder::EncodingType::k4X);
	m_pEncoder->SetPIDSourceParameter(Encoder::PIDSourceParameter::kAngle);
	m_pPIDController = new PIDController(0.25, 1.0, 0.0, m_pEncoder, m_pPaddleMotor);
}

Paddle::~Paddle()
{
	delete m_pEncoder;
	delete m_pPIDController;
	delete m_pPaddleMotor;
}

void Paddle::InitDefaultCommand()
{
}

Talon* Paddle::GetTalon()
{
	return m_pPaddleMotor;
}

PIDController* Paddle::GetPIDController()
{
	return m_pPIDController;
}
