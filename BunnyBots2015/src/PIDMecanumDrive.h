/*
 * PIDRobotDrive.h
 *
 *  Created on: Oct 16, 2015
 *      Author: t_buckm
 */

#ifndef SRC_PIDROBOTDRIVE_H_
#define SRC_PIDROBOTDRIVE_H_

#include <Talon.h>
#include <PIDController.h>
#include <PIDSource.h>
#include <Encoder.h>

class PIDMecanumDrive
{
private:
	Talon* m_pFrontLeftTalon;
	Talon* m_pRearLeftTalon;
	Talon* m_pFrontRightTalon;
	Talon* m_pRearRightTalon;

	PIDController* m_pFrontLeftPIDController;
	PIDController* m_pRearLeftPIDController;
	PIDController* m_pFrontRightPIDController;
	PIDController* m_pRearRightPIDController;

	double* m_pWheelSpeeds;

	class RobotDrivePIDSource : public PIDSource
	{
	private:
		Encoder* m_pEncoder;
	public:
		RobotDrivePIDSource(Encoder* pEncoder)
			: m_pEncoder(pEncoder)
		{
		}

		double PIDGet()
		{
			return m_pEncoder->GetRate();
		}
	};

	void Normalize(double* pWheelSpeeds, int numWheels);

public:
	PIDMecanumDrive(
			uint32_t frontLeftMotorChannel, Encoder* pFrontLeftEncoder,
			uint32_t rearLeftMotorChannel, Encoder* pRearLeftEncoder,
			uint32_t frontRightMotorChannel, Encoder* pFrontRightEncoder,
			uint32_t rearRightMotorChannel, Encoder* pRearRightEncoder,
			float p, float i, float d, float tolerance);

	~PIDMecanumDrive();

	void Drive(float x, float y, float rotation);
};

#endif /* SRC_PIDROBOTDRIVE_H_ */
