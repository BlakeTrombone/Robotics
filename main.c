#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port3,           leftMotor,     tmotorNormal, openLoop)
#pragma config(Motor,  port4,           claw,          tmotorNormal, openLoop)

task main ()
{

  while(1 == 1)
  {
    motor[leftMotor]  = (vexRT[Ch2] + vexRT[Ch1])/2;
    motor[rightMotor] = (vexRT[Ch2] - vexRT[Ch1])/2;
  }
}