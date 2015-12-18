/*
 * PIDRobotDrive.cpp
 *
 *  Created on: Oct 16, 2015
 *      Author: t_buckm
 */

#include "PIDMecanumDrive.h"
#include "../RobotMap.h"
#include "../Commands/PIDDriveFromJoystick.h"

PIDMecanumDrive::PIDMecanumDrive()
		: Subsystem("PIDMecanumDrive"),
		  m_pWheelSpeeds(new double[4] { 0.0, 0.0, 0.0, 0.0 })
{
	m_pFrontLeftEncoder = new Encoder(
			RobotMap::FRONT_LEFT_ENCODER_PORT_A,
			RobotMap::FRONT_LEFT_ENCODER_PORT_B);

	m_pRearLeftEncoder = new Encoder(
			RobotMap::REAR_LEFT_ENCODER_PORT_A,
			RobotMap::REAR_LEFT_ENCODER_PORT_B);

	m_pFrontRightEncoder = new Encoder(
			RobotMap::FRONT_RIGHT_ENCODER_PORT_A,
			RobotMap::FRONT_RIGHT_ENCODER_PORT_B);

	m_pRearRightEncoder = new Encoder(
			RobotMap::REAR_RIGHT_ENCODER_PORT_A,
			RobotMap::REAR_RIGHT_ENCODER_PORT_B);

	m_pFrontLeftTalon = new Talon(RobotMap::FRONT_LEFT_MOTOR_PORT);
	m_pRearLeftTalon = new Talon(RobotMap::REAR_LEFT_MOTOR_PORT);
	m_pFrontRightTalon = new Talon(RobotMap::FRONT_RIGHT_MOTOR_PORT);
	m_pRearRightTalon = new Talon(RobotMap::REAR_RIGHT_MOTOR_PORT);

	m_pFrontLeftPIDController = new PIDController(
			m_P, m_I, m_D,
			(PIDSource*)m_pFrontLeftEncoder,
			(PIDOutput*)m_pFrontLeftTalon);

	m_pRearLeftPIDController = new PIDController(
			m_P, m_I, m_D,
			(PIDSource*)m_pRearLeftEncoder,
			(PIDOutput*)m_pRearLeftTalon);

	m_pFrontRightPIDController = new PIDController(
			m_P, m_I, m_D,
			(PIDSource*)m_pFrontRightEncoder,
			(PIDOutput*)m_pFrontRightTalon);

	m_pRearRightPIDController = new PIDController(
			m_P, m_I, m_D,
			(PIDSource*)m_pRearRightEncoder,
			(PIDOutput*)m_pRearRightTalon);

	m_pFrontLeftPIDController->SetContinuous(false);
	m_pFrontLeftPIDController->SetAbsoluteTolerance(m_TOLERANCE);

	m_pRearLeftPIDController->SetContinuous(false);
	m_pRearLeftPIDController->SetAbsoluteTolerance(m_TOLERANCE);

	m_pFrontRightPIDController->SetContinuous(false);
	m_pFrontRightPIDController->SetAbsoluteTolerance(m_TOLERANCE);

	m_pRearRightPIDController->SetContinuous(false);
	m_pRearRightPIDController->SetAbsoluteTolerance(m_TOLERANCE);
}

PIDMecanumDrive::~PIDMecanumDrive()
{
	delete m_pFrontLeftEncoder;
	delete m_pRearLeftEncoder;
	delete m_pFrontRightEncoder;
	delete m_pRearRightEncoder;

	delete m_pFrontLeftTalon;
	delete m_pRearLeftTalon;
	delete m_pFrontRightTalon;
	delete m_pRearRightTalon;

	delete m_pFrontLeftPIDController;
	delete m_pRearLeftPIDController;
	delete m_pFrontRightPIDController;
	delete m_pRearRightPIDController;

	delete[] m_pWheelSpeeds;
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

void PIDMecanumDrive::InitDefaultCommand()
{
	SetDefaultCommand(new PIDDriveFromJoystick());
}

void PIDMecanumDrive::DriveSetSpeed(float x, float y, float rotation)
{
	m_pFrontLeftEncoder->SetPIDSourceParameter(PIDSource::PIDSourceParameter::kRate);
	m_pRearLeftEncoder->SetPIDSourceParameter(PIDSource::PIDSourceParameter::kRate);
	m_pFrontRightEncoder->SetPIDSourceParameter(PIDSource::PIDSourceParameter::kRate);
	m_pRearRightEncoder->SetPIDSourceParameter(PIDSource::PIDSourceParameter::kRate);

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

void PIDMecanumDrive::DriveForDistance(float xFeet, float yFeet, float rotationFeet)
{
	m_pFrontLeftEncoder->SetPIDSourceParameter(PIDSource::PIDSourceParameter::kAngle);
	m_pRearLeftEncoder->SetPIDSourceParameter(PIDSource::PIDSourceParameter::kAngle);
	m_pFrontRightEncoder->SetPIDSourceParameter(PIDSource::PIDSourceParameter::kAngle);
	m_pRearRightEncoder->SetPIDSourceParameter(PIDSource::PIDSourceParameter::kAngle);

	float xAngle = xFeet * m_CIRCUMFERENCE;
	float yAngle = yFeet * m_CIRCUMFERENCE;
	float rotationAngle = rotationFeet * m_CIRCUMFERENCE;

	m_pWheelSpeeds[0] = xAngle - yAngle + rotationAngle;
	m_pWheelSpeeds[1] = -xAngle - yAngle - rotationAngle;
	m_pWheelSpeeds[2] = -xAngle - yAngle + rotationAngle;
	m_pWheelSpeeds[4] = xAngle - yAngle - rotationAngle;

	m_pFrontLeftPIDController->SetSetpoint(m_pWheelSpeeds[0]);
	m_pRearLeftPIDController->SetSetpoint(m_pWheelSpeeds[1]);
	m_pFrontRightPIDController->SetSetpoint(m_pWheelSpeeds[2]);
	m_pRearRightPIDController->SetSetpoint(m_pWheelSpeeds[3]);
}

void PIDMecanumDrive::Enable()
{
	m_pFrontLeftPIDController->Enable();
	m_pRearLeftPIDController->Enable();
	m_pFrontRightPIDController->Enable();
	m_pRearRightPIDController->Enable();
}

void PIDMecanumDrive::Reset()
{
	m_pFrontLeftPIDController->Reset();
	m_pRearLeftPIDController->Reset();
	m_pFrontRightPIDController->Reset();
	m_pRearRightPIDController->Reset();
}
