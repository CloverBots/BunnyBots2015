#include "BunnyClaw.h"
#include "../RobotMap.h"

BunnyClaw::BunnyClaw() :
		Subsystem("BunnyClaw")
{
	m_pClawVictor = new Victor(10);
}

void BunnyClaw::InitDefaultCommand()
{

}
