#include "DriveFromPresets.h"

DriveFromPresets::DriveFromPresets(float xFeet, float yFeet, float rotation)
: m_x(xFeet), m_y(yFeet), m_rotation(rotation)
{
	Requires(CommandBase::pPIDMecanumDrive);
}

void DriveFromPresets::Initialize()
{
	CommandBase::pPIDMecanumDrive->DriveForDistance(m_x, m_y, m_rotation);
}

void DriveFromPresets::Execute()
{

}

bool DriveFromPresets::IsFinished()
{
	return true;
}

void DriveFromPresets::End()
{

}

void DriveFromPresets::Interrupted()
{

}
