#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port4,           claw,          tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port5,           rot,           tmotorServoContinuousRotation, openLoop)

task main ()
{

  while(1 == 1)
  {
    motor[leftMotor]  = (vexRT[Ch2] + vexRT[Ch1])/2;
    motor[rightMotor] = (vexRT[Ch2] - vexRT[Ch1])/2;
    motor[rot] = vexRT[Ch1];
    motor[claw] = vexRT[Ch2];
  }
}
