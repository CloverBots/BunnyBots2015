#include "PIDDriveFromPresets.h"

PIDDriveFromPresets::PIDDriveFromPresets(float xFeet, float yFeet, float rotation)
: CommandBase("PIDDriveFromPresets"), m_x(xFeet), m_y(yFeet), m_rotation(rotation)
{
	//Requires(CommandBase::pPIDMecanumDrive);
}

void PIDDriveFromPresets::Initialize()
{
	//CommandBase::pPIDMecanumDrive->DriveForDistance(m_x, m_y, m_rotation);
}

void PIDDriveFromPresets::Execute()
{
}

bool PIDDriveFromPresets::IsFinished()
{
	return true;
}

void PIDDriveFromPresets::End()
{
}

void PIDDriveFromPresets::Interrupted()
{
}
