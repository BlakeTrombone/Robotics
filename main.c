#pragma config(Sensor, dgtl1,  left,           sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  right,          sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  spin,           sensorQuadEncoder)
#pragma config(Sensor, dgtl7,  tilt,           sensorQuadEncoder)
#pragma config(Sensor, dgtl9,  out,            sensorQuadEncoder)
#pragma config(Motor,  port2,           right,    tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port3,           left,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port4,           claw,          tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port5,           rot,           tmotorServoContinuousRotation, openLoop)

void drive(int distance)
{
	int dist = distance / 5*PI;
	while ((SensorValue[left]+SensorValue[right])/2 < dist)
	{
		motor[left] = 127;
		motor[right] = 127;

		if (SensorValue[left]<SensorValue[right])
			if (motor[left]>=123)
				motor[right] = motor[right] - 5;
		  else motor[left] = motor[left] + 5;

		if (SensorValue[right]<SensorValue[left])
			if (motor[right]>=123)
				motor[left] = motor[left] - 5;
		  else motor[right] = motor[right] + 5;

	}
}


void turn(int degrees)
{
	int cos = (degrees/360) * 0 * PI; //REPLACE 0 WITH ROBOT WIDTH (DIAMETER)
	if (degrees < 0)
		while (SensorValue[left]-SensorValue[right]<cos)
		{
			motor[left] = -127;
			motor[right] = 127;
		}

	if (degrees > 0)
		while (SensorValue[right]-SensorValue[left]<cos)
		{
			motor[left] = 127;
			motor[right] = -127;
		}
}
task main ()
{
	SensorValue[left] = 0;
  SensorValue[right] = 0;
	SensorValue[spin] = 0;
	SensorValue[tilt] = 0;
	SensorValue[out] = 0;






  while(1 == 1)
  {
    motor[left]  = (vexRT[Ch2] + vexRT[Ch1])/2;
    motor[right] = (vexRT[Ch2] - vexRT[Ch1])/2;
    motor[rot] = vexRT[Ch1];
    motor[claw] = vexRT[Ch2];
  }
}
