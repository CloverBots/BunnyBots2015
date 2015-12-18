#ifndef BunnyClaw_H
#define BunnyClaw_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class BunnyClaw: public Subsystem
{
private:

	Talon* m_pClawTalon;
	Victor* m_pClawVictor;
	DigitalInput* m_pLowerLimitSwitch;
	DigitalInput* m_pUpperLimitSwitch;

public:
	BunnyClaw();
	~BunnyClaw();

	void InitDefaultCommand();

	void SetLiftSpeed(float speed);
	void SetGrabSpeed(float speed);

	bool IsLowerLimitReached();
	bool IsUpperLimitReached();
};

#endif
