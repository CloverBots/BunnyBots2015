#ifndef LowerClaw_H
#define LowerClaw_H

#include "../CommandBase.h"
#include "WPILib.h"

class LowerClaw: public CommandBase
{
public:
	LowerClaw();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
