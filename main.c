#pragma config(Sensor, dgtl1,  fleft,          sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  fright,         sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  bleft,          sensorQuadEncoder)
#pragma config(Sensor, dgtl7,  bright,         sensorQuadEncoder)
#pragma config(Sensor, dgtl9,  spinner,        sensorQuadEncoder)
#pragma config(Motor,  port1,           back,          tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           right,         tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port3,           left,          tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port4,           right,         tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port5,           left,          tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port6,           claw,          tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port7,           spinner,       tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port8,           push,          tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port9,           arm,           tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port10,          back,          tmotorVex393_HBridge, openLoop)

void clear() //clears encoders
{
	SensorValue[fleft] = 0;
  SensorValue[fright] = 0;
  SensorValue[bleft] = 0;
  SensorValue[bright] = 0;
	SensorValue[spinner] = 0;
}

void drive(int distance)
{
	clear(); //clears encoders for accurate measurments
	int dist = distance / 5*PI; //finds the distance from degrees for the wheels
	while ((((SensorValue[fleft]+SensorValue[fright])/2)+((SensorValue[fleft]+SensorValue[fright])/2))/2< dist)//while the sensors have a lower value than the distance
	{
		motor[left] = 127;//left motors full speed forward
		motor[right] = 127;// right motors full speed forward

		if ((SensorValue[fleft] + SensorValue[bleft])/2<(SensorValue[fright]+SensorValue[bright])/2)//if the average left encoders are less than the average of the right encoders...
			if (motor[left]>=123)//... and the left motor is running full speed...
				motor[right] = motor[right] - 5;//... lower the right motor speed
		  else motor[left] = motor[left] + 5;//if the left motor isn't running full speed, raise it up a notch.

		if ((SensorValue[fleft] + SensorValue[bleft])/2>(SensorValue[fright]+SensorValue[bright])/2)//if the average right encoders are less than the average of the left encoders...
			if (motor[right]>=123)//... and the right motor is running full speed...
				motor[left] = motor[left] - 5;//... lower the left motor speed
		  else motor[right] = motor[right] + 5;//if the right motor isn't running full speed, raise it up a notch.

	}
	motor[left] = 0;
	motor[right] = 0;
}


void turn(int degrees)
{
	clear();//clears encoders for accurate measurments
	int cos = ((degrees/360) * D / PI)/(5*PI); //REPLACE D WITH ROBOT WIDTH (DIAMETER)          convert degrees to turn into degrees per wheel
	if (degrees < 0) //if it needs to turn counter-clockwise...
		while ((SensorValue[fleft]+SensorValue[bleft])/2-(SensorValue[fright]+SensorValue[bright])/2<cos) //if the difference is less than the required...
		{
			motor[left] = -127; // left motor full speed backwards
			motor[right] = 127;//right motor full speed ahead
		}

	if (degrees > 0) // if it needs to spin clockwise
		while ((SensorValue[fleft]+SensorValue[bleft])/2-(SensorValue[fright]+SensorValue[bright])/2>cos)//if the difference is less than required
		{
			motor[left] = 127;//left motor full speed ahead
			motor[right] = -127;//right motor full speed backwards
		}
}

void spin(int degrees)
{
	clear();//clears encoders for accurate measurments
	if (degrees < 0)// if it needs to spin counter-clockwise...
		while (degrees <SensorValue[spinner])//while the degrees are less than required
			motor[spinner] = -127;//spin backwards
	if (degrees > 0)//if it needs to spin clockwise...
		while (degrees > SensorValue[spinner])//while the degrees are less than required...
			motor[spinner] = 127;//spin forwards
}



task main ()
{
	clear();
	//autonomous








  while(1 == 1)
  {
    motor[left]  = (vexRT[Ch2] + vexRT[Ch1])/2;
    motor[right] = (vexRT[Ch2] - vexRT[Ch1])/2;
    motor[spinner] = vexRT[Ch4];
    motor[arm] = vexRT[Ch3];
    if (vexRT[Btn5D]==1)
    	motor[back] = -127;
    else motor[back] = 0;

    if (vexRT[Btn5U]==1)
    	motor[back] = 127;
    else motor[back] = 0;

    if (vexRT[Btn6U]==1)
    	motor[claw] = 127;
    else motor[claw] = 0;

    if (vexRT[Btn6D]==1)
    	motor[claw] = -127;
    else motor[claw] = 0;

    if (vexRT[Btn7U]==1)
    	motor[push] = 127;
    else motor[push] = 0;

    if (vexRT[Btn7D]==1)
    	motor[push] = -127;
    else motor[push] = 0;
  }
}
