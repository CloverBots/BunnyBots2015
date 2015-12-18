#ifndef BunnyClaw_H
#define BunnyClaw_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class BunnyClaw: public Subsystem
{
private:

	Victor* m_pClawVictor;

public:
	BunnyClaw();
	void InitDefaultCommand();
};

#endif
