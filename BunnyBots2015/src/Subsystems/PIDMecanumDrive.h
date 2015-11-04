/*
 * PIDRobotDrive.h
 *
 *  Created on: Oct 16, 2015
 *      Author: t_buckm
 */

#ifndef SRC_PIDROBOTDRIVE_H_
#define SRC_PIDROBOTDRIVE_H_

#include <WPILib.h>
#include <Talon.h>
#include <PIDController.h>
#include <PIDSource.h>
#include <PIDOutput.h>
#include <Encoder.h>
#include <cmath>

class PIDMecanumDrive : public Subsystem
{
private:
	Encoder* m_pFrontLeftEncoder;
	Encoder* m_pRearLeftEncoder;
	Encoder* m_pFrontRightEncoder;
	Encoder* m_pRearRightEncoder;

	Talon* m_pFrontLeftTalon;
	Talon* m_pRearLeftTalon;
	Talon* m_pFrontRightTalon;
	Talon* m_pRearRightTalon;

	PIDController* m_pFrontLeftPIDController;
	PIDController* m_pRearLeftPIDController;
	PIDController* m_pFrontRightPIDController;
	PIDController* m_pRearRightPIDController;

	double* m_pWheelSpeeds;

	const float m_P = 0.1f;
	const float m_I = 1.0f;
	const float m_D = 0.0f;
	const float m_TOLERANCE = 2.0f;
	const float m_RADIUS = 2.0f;
	const float m_CIRCUMFERENCE = M_PI * m_RADIUS;

	void Normalize(double* pWheelSpeeds, int numWheels);

public:
	PIDMecanumDrive();
	~PIDMecanumDrive();

	void InitDefaultCommand();
	void DriveSetSpeed(float x, float y, float rotation);
	void DriveForDistance(float xFeet, float yFeet, float rotationFeet);
	void Enable();
	void Reset();
	bool IsEnabled();
};

#endif /* SRC_PIDROBOTDRIVE_H_ */
