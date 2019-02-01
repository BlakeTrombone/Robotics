#pragma config(Sensor, dgtl1,  armLeft,        sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  armRight,        sensorQuadEncoder)
#pragma config(Motor,  port1,           bLeftMotor,    tmotorNone, openLoop)
#pragma config(Motor,  port2,           bRightMotor,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           fLeftMotor,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           fRightMotor,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           armLeftMotor,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           armRightMotor, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           handMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           pinballMotor,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           suckerMotor,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          lifterMotor,   tmotorVex393_HBridge, openLoop)

#include  "JoystickDriver.c"
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/


void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks
  // running between Autonomous and Driver controlled modes. You will need to
  // manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

  motor[armLeftMotor] = motor[armRightMotor] = 127;
  wait1Msec(500);
  motor[armLeftMotor]=motor[armRightMotor]=0;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous()
{
  // ..........................................................................
  // Insert user code here.
		bool left = true;//are you on the left square or the right square?
		bool right=!left;//this is just to make the code more human friendly

		if (left)//auto code for if you're on the left square
		{
			motor[armLeftMotor] = motor[armRightMotor] = 127;//begin lifting arm up
   	  wait1Msec(500);//modify to proper height for flag
	 	  motor[armLeftMotor]=motor[armRightMotor]=0;//stop lifting arm
			motor[bRightMotor]=motor[fRightMotor]=127;//turn left
			wait1Msec(500);//adjust for when robot is facing left
      motor[bLeftMotor]=motor[fLeftMotor]=127;//start going straight
			wait1Msec(5000);
			motor[bLeftMotor]=motor[fLeftMotor]=0;//stop left motors
			motor[bRightMotor]=motor[fRightMotor]=0;//stop right motors
		}

		if (right)//auto code for if you're on the right square
		{





		}

  // ..........................................................................

  // Remove this function call once you have "real" code.
  AutonomousCodePlaceholderForTesting();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol()
{
  // User control code here, inside the loop

  while (true)
  {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    // Remove this function call once you have "real" code.
    motor[bLeftMotor]=motor[fLeftMotor]= vexRT[Ch3];
    motor[bRightMotor]=motor[fRightMotor] =vexRT[Ch2];

    motor[armLeftMotor]=motor[armRightMotor]= (vexRT[Btn5UXmtr2]-vexRT[Btn5DXmtr2])*65;
    motor[suckerMotor]=127;
    motor[handMotor]=vexRT[Ch4Xmtr2];

    motor[lifterMotor]=(vexRT[Btn6UXmtr2]-vexRT[Btn6DXmtr2])*127;
    motor[pinballMotor]=vexRT[Ch2Xmtr2];



    /*  THIS IS JUST IN CASE THE OTHER CODE DOESN'T WORK
    motor[bLeftMotor]  = (vexRT[Ch2] + vexRT[Ch1])/2;  // (y + x)/2
    motor[bRightMotor] = (vexRT[Ch2] - vexRT[Ch1])/2;  // (y - x)/2
    motor[fLeftMotor]  = (vexRT[Ch2] + vexRT[Ch1])/2;  // (y + x)/2
    motor[fRightMotor] = (vexRT[Ch2] - vexRT[Ch1])/2;  // (y - x)/2

    motor[armLeftMotor]=vexRT[Ch3];
    motor[armRightMotor]=vexRT[Ch3];
    motor[suckerMotor]=127;
    motor[handMotor]=vexRT[Ch4];
    if (vexRT[Btn7L])
    {
       clearTimer(T1);
    	 motor[lifterMotor]=127;
    }
    if(time10[T1]>=1000 && time10[T1]<=1050)
    {
        motor[lifterMotor]=0;
        motor[pinballMotor]=127;
    }

    if(time10[T1]>=2000 && time10[T1]<=2050)
    {
        motor[pinballMotor]=0;
        motor[lifterMotor]=-127;
    }

    if(time10[T1]>=3000 && time10[T1]<=3050)
        motor[lifterMotor]=0;
*/
  }
}
