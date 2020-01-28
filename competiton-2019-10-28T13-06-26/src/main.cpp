/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\blake.eastman                                    */
/*    Created:      Mon Oct 28 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;
// A global instance of vex::competition
vex::competition Competition;

// define your global instances of motors and other devices here
vex::motor        driveLeft(PORT2, gearSetting::ratio18_1, false);
vex::motor        driveRight(PORT1, gearSetting::ratio18_1, true);

vex::motor        armLeft(PORT4, gearSetting::ratio18_1, false);
vex::motor        armRight(PORT3, gearSetting::ratio18_1, true);

vex::motor        suckLeft(PORT9, gearSetting::ratio18_1, true);
vex::motor        suckRight(PORT5, gearSetting::ratio18_1, false);

vex::motor        lean(PORT7, gearSetting::ratio18_1, false);

vex::controller   Controller1(vex::controllerType::primary);
vex::controller   Controller2(vex::controllerType::partner);

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */ 
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton( void ) {
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
armLeft.setRotation(0, vex::rotationUnits::deg);
armRight.setRotation(0, vex::rotationUnits::deg);
  
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

void autonomous( void ) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
  

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
void usercontrol( void ) {
  armLeft.setRotation(0, vex::rotationUnits::deg);
  armRight.setRotation(0, vex::rotationUnits::deg);
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo 
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to 
    // update your motors, etc.
    // ........................................................................
  armLeft.stop(vex::brakeType::hold);
  armRight.stop(vex::brakeType::hold);
  
  driveLeft.spin(vex::directionType::fwd,Controller1.Axis3.position(), vex::velocityUnits::pct); 
  driveRight.spin(vex::directionType::fwd,Controller1.Axis2.position(), vex::velocityUnits::pct);

    //armLeft.spin(vex::directionType::fwd, .2*Controller2.Axis3.position(), vex::velocityUnits::pct);
    //armRight.spin(vex::directionType::fwd, .2*Controller2.Axis3.position(), vex::velocityUnits::pct);

    //suckLeft.spin(vex::directionType::fwd,Controller2.Axis2.position() , vex::velocityUnits::pct);
    //suckRight.spin(vex::directionType::fwd,Controller2.Axis2.position(), vex::velocityUnits::pct);

  if (Controller1.ButtonA.pressing())
  {
    armLeft.stop(vex::brakeType::coast);
    armRight.stop(vex::brakeType::coast);
  }

  if (Controller1.ButtonB.pressing())
    {
      armLeft.startRotateTo(0, vex::rotationUnits::deg);
      armRight.startRotateTo(0, vex::rotationUnits::deg);

      suckLeft.spin(vex::directionType::fwd, -100, vex::velocityUnits::pct);
      suckRight.spin(vex::directionType::fwd, -100, vex::velocityUnits::pct);
      vexDelay(500);

      armLeft.startRotateTo(-70, vex::rotationUnits::deg);
      armRight.startRotateTo(-70, vex::rotationUnits::deg);

      vexDelay(2000);

      armLeft.startRotateTo(0, vex::rotationUnits::deg);
      armRight.startRotateTo(0, vex::rotationUnits::deg);

      suckLeft.spin(vex::directionType::fwd, 0, vex::velocityUnits::pct);
      suckRight.spin(vex::directionType::fwd, 0, vex::velocityUnits::pct);

      vexDelay(1000);
      armLeft.stop(vex::brakeType::hold);
      armRight.stop(vex::brakeType::hold);
    }

    lean.spin(vex::directionType::fwd, .5*((100*Controller1.ButtonL2.pressing())-(100*Controller1.ButtonL1.pressing())), vex::velocityUnits::pct);
    vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources. 
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
    //Set up callbacks for autonomous and driver control periods.
    Competition.autonomous( autonomous );
    Competition.drivercontrol( usercontrol );
    
    //Run the pre-autonomous function. 
    pre_auton();
       
    //Prevent main from exiting with an infinite loop.                        
    while(1) {
      vex::task::sleep(100);//Sleep the task for a short amount of time to prevent wasted resources.
    }   
       
}

