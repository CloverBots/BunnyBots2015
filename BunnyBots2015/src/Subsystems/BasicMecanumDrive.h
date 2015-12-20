#ifndef MecanumDrive_H
#define MecanumDrive_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class BasicMecanumDrive: public Subsystem
{
private:

	Talon* m_pFrontLeftMotor;
	Talon* m_pRearLeftMotor;
	Talon* m_pFrontRightMotor;
	Talon* m_pRearRightMotor;

	RobotDrive* m_pRobotDrive;

	float m_xSpeed;
	float m_ySpeed;
	float m_rotSpeed;

public:
	BasicMecanumDrive();
	~BasicMecanumDrive();

	void InitDefaultCommand();

	void Drive(float xSpeed, float ySpeed, float rotSpeed);
	void SetSafetyEnabled(bool enabled);
	float GetXSpeed();
	float GetYSpeed();
	float GetRotSpeed();
};

#endif
