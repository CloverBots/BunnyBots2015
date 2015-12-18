#ifndef Paddle_H
#define Paddle_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Paddle: public Subsystem
{
private:
	const float m_P = 0.25f;
	const float m_I = 1.0f;
	const float m_D = 0.0f;

	Talon* m_pLeftPaddleMotor;
	Talon* m_pRightPaddleMotor;

	Encoder* m_pEncoder;

	PIDController* m_pPIDLeftController;
	PIDController* m_pPIDRightController;
public:
	Paddle();
	~Paddle();

	void InitDefaultCommand();
	void SetAngle(float angle);
};

#endif
