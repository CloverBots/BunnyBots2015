#ifndef Paddle_H
#define Paddle_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Paddle: public Subsystem
{
private:

	const float m_P = 1.5f;
	const float m_I = 0.0f;
	const float m_D = 0.0f;

	Encoder* m_pEncoder;

	PIDController* m_pPIDController;

	class PaddlePIDOutput : public PIDOutput
	{
	private:

		Talon* m_pLeftTalon;
		Talon* m_pRightTalon;
		bool m_leftInverted;
		bool m_rightInverted;

	public:

		PaddlePIDOutput(uint8_t leftPort, uint8_t rightPort, bool leftInverted = false, bool rightInverted = false)
		: m_leftInverted(leftInverted), m_rightInverted(rightInverted)
		{
			m_pLeftTalon = new Talon(leftPort);
			m_pRightTalon = new Talon(rightPort);
		}

		virtual ~PaddlePIDOutput()
		{
			delete m_pLeftTalon;
			delete m_pRightTalon;
		}

		void PIDWrite(float output)
		{
			m_pLeftTalon->Set(m_leftInverted ? -output : output);
			m_pRightTalon->Set(m_rightInverted ? -output : output);
		}
	};

	PaddlePIDOutput* m_pPIDOutput;

	void UpdatePID();
public:
	Paddle();
	~Paddle();

	void InitDefaultCommand();
	void SetEnabled(bool enabled);
	float GetRate();
	void SetAngle(float angle);
};

#endif
