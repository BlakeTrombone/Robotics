#pragma config(Motor,  port2,           backleft,    tmotorNormal, openLoop)
#pragma config(Motor,  port3,           frontleft,     tmotorNormal, openLoop)
#pragma config(Motor,  port4,           backright,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port5,           frontright,     tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port5,           height,     tmotorNormal, openLoop)

/*----------------------------------------------------------------------------------------------------*\
|*                           - Dual Joystick Control with Arm - 1 Remote -                            *|
|*                                      ROBOTC on VEX 2.0 Cortex                                      *|
|*                                                                                                    *|
|*  This program uses both the Left and the Right joysticks to run the robot using "tank control".    *|
|*  The Group 6 buttons on the top-right of the VEXnet Joystick are used to raise and lower an arm.   *|
|*                                                                                                    *|
|*                                        ROBOT CONFIGURATION                                         *|
|*    NOTES:                                                                                          *|
|*    1)  Ch1 is the X axis and Ch2 is the Y axis for the RIGHT joystick.                             *|
|*    2)  Ch3 is the Y axis and Ch4 is the X axis for the LEFT joystick.                              *|
|*                                                                                                    *|
|*    MOTORS & SENSORS:                                                                               *|
|*    [I/O Port]              [Name]              [Type]              [Description]                   *|
|*    Motor - Port 2          rightMotor           VEX Motor           Right motor                    *|
|*    Motor - Port 3          leftMotor            VEX Motor           Left motor                     *|
|*    Motor - Port 6          armMotor             VEX Motor           Arm motor                      *|
\*----------------------------------------------------------------------------------------------------*/

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++

task main()
{
  while(1 == 1)
  {
    //Driving Motor Control
    motor[frontleft] = vexRT[Ch3] / 2;
    motor[frontright] = vexRT[Ch2] / 2;
	motor[backleft] = vexRT[Ch3] / 2;
    motor[backright] = vexRT[Ch2] / 2;

    //Arm Control
    /*
	if(vexRT[Btn6U] == 1)
    {
      motor[armMotor] = 40;
    }
    else if(vexRT[Btn6D] == 1)
    {
      motor[armMotor] = -40;
    }
    else
    {
      motor[armMotor] = 0;
    }
  }
  */
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
