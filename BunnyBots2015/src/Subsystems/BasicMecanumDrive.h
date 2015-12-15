#ifndef MecanumDrive_H
#define MecanumDrive_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class BasicMecanumDrive: public Subsystem
{
private:

	CANTalon* m_pFrontLeftMotor;
	CANTalon* m_pRearLeftMotor;
	CANTalon* m_pFrontRightMotor;
	CANTalon* m_pRearRightMotor;

	RobotDrive* m_pRobotDrive;

	float m_xSpeed;
	float m_ySpeed;
	float m_rotSpeed;

public:
	BasicMecanumDrive();
	~BasicMecanumDrive();

	void InitDefaultCommand();

	void Drive(float xSpeed, float ySpeed, float rotSpeed);
	float GetXSpeed();
	float GetYSpeed();
	float GetRotSpeed();
};

#endif
