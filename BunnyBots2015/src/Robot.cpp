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
		//pAutonomousChooser = new SendableChooser();
		//pAutonomousChooser->AddDefault("Drive straight for 10ft", new AutonomousCommand());
		//autonomousCommand = (AutonomousCommand*)pAutonomousChooser->GetSelected();
		lw = LiveWindow::GetInstance();
	}
	
	void DisabledInit()
	{
//		CommandBase::pBasicMecanumDrive->Reset();
	}

	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
//		CommandBase::pBasicMecanumDrive->Enable();

		if (autonomousCommand != NULL)
			autonomousCommand->Start();
	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit()
	{
		if (autonomousCommand != NULL)
			autonomousCommand->Cancel();

//		CommandBase::pBasicMecanumDrive->Enable();
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
