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
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"

//http://www.robotc.net/wikiarchive/VEX2_Functions_Remote_Control_-_VEXnet link to explain multiple remotes


task main()
{
  while(true){
    motor[bLeftMotor]  = vexRT[Ch3];
    motor[bRightMotor] = vexRT[Ch2];

    motor[fLeftMotor]  = vexRT[Ch3];
    motor[fRightMotor] = VexRT[Ch2];

    motor[armLeftMotor]=(vexRT[Btn5UXmrt2]-vexRT[Btn5DXmrt2])*65;//5
    motor[armRightMotor]=(vexRT[Btn5UXmrt2]-vexRT[Btn5DXmrt2])*65;//5
    motor[suckerMotor]=127;
    motor[handMotor]=vexRT[Ch4Xmrt2];//left joystick

    motor[lifterMotor]=(vexRT[Btn6UXmrt2]-vexRT[Btn6DXmrt2])*127;
    motor[pinballMotor]=vexRT[Ch2Xmrt2];
//lifter 6
//pinball joystick
  }
}
