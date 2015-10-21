/*
 * PIDRobotDrive.cpp
 *
 *  Created on: Oct 16, 2015
 *      Author: t_buckm
 */

#include <PIDMecanumDrive.h>
#include <CANJaguar.h>
#include <NetworkCommunication/UsageReporting.h>

PIDMecanumDrive::PIDMecanumDrive(
		uint32_t frontLeftMotorChannel, Encoder* pFrontLeftEncoder,
		uint32_t rearLeftMotorChannel, Encoder* pRearLeftEncoder,
		uint32_t frontRightMotorChannel, Encoder* pFrontRightEncoder,
		uint32_t rearRightMotorChannel, Encoder* pRearRightEncoder,
		float p, float i, float d, float tolerance)
		: m_pWheelSpeeds(new double[4] { 0.0, 0.0, 0.0, 0.0 })
{
	m_pFrontLeftTalon = new Talon(frontLeftMotorChannel);
	m_pRearLeftTalon = new Talon(rearLeftMotorChannel);
	m_pFrontRightTalon = new Talon(frontRightMotorChannel);
	m_pRearRightTalon = new Talon(rearRightMotorChannel);

	m_pFrontLeftPIDController = new PIDController(p, i, d,
			new RobotDrivePIDSource(pFrontLeftEncoder), (PIDOutput*)m_pFrontLeftTalon);
	m_pRearLeftPIDController = new PIDController(p, i, d,
			new RobotDrivePIDSource(pRearLeftEncoder), (PIDOutput*)m_pRearLeftTalon);
	m_pFrontRightPIDController = new PIDController(p, i, d,
			new RobotDrivePIDSource(pFrontRightEncoder), (PIDOutput*)m_pFrontRightTalon);
	m_pRearRightPIDController = new PIDController(p, i, d,
			new RobotDrivePIDSource(pRearRightEncoder), (PIDOutput*)m_pRearRightTalon);

	m_pFrontLeftPIDController->SetContinuous(false);
	m_pFrontLeftPIDController->SetAbsoluteTolerance(tolerance);

	m_pRearLeftPIDController->SetContinuous(false);
	m_pRearLeftPIDController->SetAbsoluteTolerance(tolerance);

	m_pFrontRightPIDController->SetContinuous(false);
	m_pFrontRightPIDController->SetAbsoluteTolerance(tolerance);

	m_pRearRightPIDController->SetContinuous(false);
	m_pRearRightPIDController->SetAbsoluteTolerance(tolerance);

	m_pFrontLeftPIDController->Enable();
	m_pRearLeftPIDController->Enable();
	m_pFrontRightPIDController->Enable();
	m_pRearRightPIDController->Enable();
}

PIDMecanumDrive::~PIDMecanumDrive()
{
	delete[] m_pWheelSpeeds;

	delete m_pFrontLeftTalon;
	delete m_pRearLeftTalon;
	delete m_pFrontRightTalon;
	delete m_pRearRightTalon;

	delete m_pFrontLeftPIDController;
	delete m_pRearLeftPIDController;
	delete m_pFrontRightPIDController;
	delete m_pRearRightPIDController;
}

void PIDMecanumDrive::Normalize(double* pWheelSpeeds, int numWheels)
{
	double maxMagnitude = fabs(pWheelSpeeds[0]);
	int32_t i;
	for (i = 1; i < numWheels; i++)
	{
		double temp = fabs(pWheelSpeeds[i]);
		if (maxMagnitude < temp) maxMagnitude = temp;
	}
	if (maxMagnitude > 1.0)
	{
		for (i = 0; i < numWheels; i++)
		{
			pWheelSpeeds[i] = pWheelSpeeds[i] / maxMagnitude;
		}
	}
}

void PIDMecanumDrive::Drive(float x, float y, float rotation)
{
	m_pWheelSpeeds[0] = x - y + rotation;
	m_pWheelSpeeds[1] = -x - y - rotation;
	m_pWheelSpeeds[2] = -x - y + rotation;
	m_pWheelSpeeds[3] = x - y - rotation;

	Normalize(m_pWheelSpeeds, 4);

	m_pFrontLeftPIDController->SetSetpoint(m_pWheelSpeeds[0]);
	m_pRearLeftPIDController->SetSetpoint(m_pWheelSpeeds[1]);
	m_pFrontRightPIDController->SetSetpoint(m_pWheelSpeeds[2]);
	m_pRearRightPIDController->SetSetpoint(m_pWheelSpeeds[3]);
}
