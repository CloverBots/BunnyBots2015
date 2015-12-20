#include "WPILib.h"
#include "Commands/AutonomousCommand.h"
#include "CommandBase.h"

class Robot: public IterativeRobot
{
private:
	Command *autonomousCommand;
	LiveWindow *lw;
	SendableChooser *pAutonomousChooser;

	void RobotInit()
	{
		CommandBase::init();
		autonomousCommand = new AutonomousCommand();
		lw = LiveWindow::GetInstance();
		CommandBase::pPaddle->SetEnabled(true);
	}
	
	void DisabledInit()
	{
	}

	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
		CommandBase::pBasicMecanumDrive->SetSafetyEnabled(false);

		if (autonomousCommand != NULL)
			autonomousCommand->Start();
	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit()
	{
		CommandBase::pBasicMecanumDrive->SetSafetyEnabled(true);

		if (autonomousCommand != NULL)
			autonomousCommand->Cancel();
	}

	void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);
