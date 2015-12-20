#ifndef RaiseClaw_H
#define RaiseClaw_H

#include "../CommandBase.h"
#include "WPILib.h"

class RaiseClaw: public CommandBase
{
public:
	RaiseClaw();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
