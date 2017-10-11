#pragma config(Motor,  port2,           backleft,    tmotorNormal, openLoop)
#pragma config(Motor,  port3,           frontleft,     tmotorNormal, openLoop)
#pragma config(Motor,  port4,           backright,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port5,           frontright,     tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port6,           height,     tmotorNormal, openLoop)


task main()
{
  while(1 == 1)
  {
    motor[frontleft] = vexRT[Ch3] / 2;
    motor[frontright] = vexRT[Ch2] / 2;
	motor[backleft] = vexRT[Ch3] / 2;
    motor[backright] = vexRT[Ch2] / 2;

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
