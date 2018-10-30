#include <iostream>
#include <memory>
#include <string>

#include <math.h>

#include <IterativeRobot.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>

#include <WPILib.h>
#include <ctre/Phoenix.h>
#include <Brahe.h>


class Robot: public frc::IterativeRobot
{
public:
	WPI_TalonSRX *leftMotor, *rightMotor, *leftSlave, *rightSlave;
	WPI_TalonSRX *climbMotor;
	Joystick *leftJoystick, *rightJoystick;
	Relay *lightswitch;

	frc::DifferentialDrive *drive;

	void
	RobotInit()
	{
		lightswitch = new Relay(LIGHT_SWITCH);
		leftMotor = new WPI_TalonSRX(LEFT_DRIVEMOTOR);
		leftSlave = new WPI_TalonSRX(LEFT_SLAVEMOTOR);
		rightMotor = new WPI_TalonSRX(RIGHT_DRIVEMOTOR);
		rightSlave = new WPI_TalonSRX(RIGHT_SLAVEMOTOR);
		leftJoystick = new Joystick(LEFT_JOYSTICK);
		rightJoystick = new Joystick(RIGHT_JOYSTICK);

		drive = new DifferentialDrive(*leftMotor, *rightMotor);
		leftSlave->Set(ControlMode::Follower, leftMotor->GetDeviceID());
		rightSlave->Set(ControlMode::Follower, rightMotor->GetDeviceID());
	}

	void
	RobotPeriodic()
	{
	}

	void
	DisabledInit()
	{

	}

	void
	DisabledPeriodic()
	{

	}

	void
	AutonomousInit()
	{

	}

	bool
	AutonomousMobility(double dist, double lSpeed, double rSpeed)
	{

      return false;
	}

	void
	AutonomousGearPlacement()
	{

	}



	void
	AutonomousPeriodic()
	{

	}

	void
	TeleopInit()
	{
		lightswitch->Set(Relay::kForward);
	}

	void
	TeleopPeriodic()
	{
		drive->TankDrive(leftJoystick->GetY(), rightJoystick->GetY(), true);
	}

	void
	TestInit()
	{
    }

	void
	TestPeriodic()
	{

	}
};

START_ROBOT_CLASS(Robot)
