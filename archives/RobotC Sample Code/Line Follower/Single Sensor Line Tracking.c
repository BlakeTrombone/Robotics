#pragma config(Sensor, in2,    lineTracker,         sensorLineFollower)
#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port3,           leftMotor,     tmotorNormal, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*----------------------------------------------------------------------------------------------------*\
|*                                    - Single Sensor Line Track -                                    *|
|*                                      ROBOTC on VEX 2.0 CORTEX                                      *|
|*                                                                                                    *|
|*  This program uses 1 VEX Line Follower Sensor to track a black line on a light(er) surface.        *|
|*  There is a two second pause at the beginning of the program.                                      *|
|*                                                                                                    *|
|*                                        ROBOT CONFIGURATION                                         *|
|*    NOTES:                                                                                          *|
|*    1)  Reversing 'rightMotor' (port 2) in the "Motors and Sensors Setup" is needed with the        *|
|*        "Squarebot" mode, but may not be needed for all robot configurations.                       *|
|*    2)  Lighting conditions, line darkness, and surface lightness change from place to place,       *|
|*        so the value of 'threshold' may need to be changed to better suit your environment.         *|
|*                                                                                                    *|
|*    MOTORS & SENSORS:                                                                               *|
|*    [I/O Port]          [Name]              [Type]                [Description]                     *|
|*    Motor  - Port 2     rightMotor          VEX 3-wire module     Right side motor                  *|
|*    Motor  - Port 3     leftMotor           VEX 3-wire module     Left side motor                   *|
|*    Analog - Port 2     lineTracker         VEX Light Sensor      Front-center, facing down         *|
\*-----------------------------------------------------------------------------------------------4246-*/


//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{
  wait1Msec(2000);          // The program waits for 2000 milliseconds before continuing.

  int threshold = 505;      /* found by taking a reading on both DARK and LIGHT    */
                            /* surfaces, adding them together, then dividing by 2. */
  while(true)
  {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -+
    displayLCDCenteredString(0, "Light Sensor:");           //  Display   |
    displayLCDPos(1,6);                                     //  Sensor    |
    displayNextLCDNumber(SensorValue(lineTracker));         //  Readings  |
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -+

    // sensor sees light:
    if(SensorValue(lineTracker) < threshold)
    {
      // counter-steer left:
      motor[leftMotor]  = 63;
      motor[rightMotor] = 0;
    }
    // sensor sees dark:
    else
    {
      // counter-steer right:
      motor[leftMotor]  = 0;
      motor[rightMotor] = 63;
    }
  }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
