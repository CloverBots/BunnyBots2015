#include "SetPaddleAngle.h"

SetPaddleAngle::SetPaddleAngle(float angle)
: CommandBase("SetPaddleAngle"), m_paddleAngle(angle)
{
	Requires(CommandBase::pPaddle);
}

void SetPaddleAngle::Initialize()
{
	CommandBase::pPaddle->SetAngle(m_paddleAngle);
}

void SetPaddleAngle::Execute()
{
}

bool SetPaddleAngle::IsFinished()
{
	return true;
}

void SetPaddleAngle::End()
{
}

void SetPaddleAngle::Interrupted()
{
}
