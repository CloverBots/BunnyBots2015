#ifndef Paddle_H
#define Paddle_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Paddle: public Subsystem
{
private:
	Encoder* m_pEncoder;
	PIDController* m_pPIDController;
	Talon* m_pPaddleMotor;
public:
	Paddle();
	~Paddle();
	void InitDefaultCommand();
	PIDController* GetPIDController();
	Talon* GetTalon();
};

#endif
