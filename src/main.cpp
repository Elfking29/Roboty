/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/
int lor = 0;
void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  wait(0.5,sec);
  Con1.Screen.clearScreen();
  bool lb = left_button.value();
  bool rb = right_button.value();
    if (lb == false and rb == true){
      lor = 1;
      Con1.Screen.setCursor(1,1);
      Con1.Screen.print("Left");   
    wait(30,msec);  
    }
    else if (lb == true and rb == false) {
      lor = 2;
      Con1.Screen.setCursor(1,1);
      Con1.Screen.print("Right");  
    }
    else if (lb == false and rb == false){
      lor = 3;
      Con1.Screen.setCursor(1,1);
      Con1.Screen.print("Skills"); 
    }
    else if (lb == true and rb == true){
      lor = 4;
      Con1.Screen.setCursor(1,1);
      Con1.Screen.print("NONE!");      
    }

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
  //rot.setPosition(0,degrees);
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

void autonomous(void) {
  lor = 1;
  wait(30,msec);
  if (lor == 1){
    leftauton();
  }
  else if (lor == 2){
    rightauton();
  }
  else if (lor == 3){
    skillsauton();
  }
  else if (lor == 4){
  lor = 4;
  }
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

void usercontrol(void) {
  // User control code here, inside the loop
  Brain.Screen.clearScreen();
  bool toggle = false;
  bool tog = false;
  rot.setPosition(0,degrees);
  wait(20,msec);
  while (1) {
    //This code is for movement (forward/backward,left/right/shift)
    double ch1=Con1.Axis1.position();
    double ch2=Con1.Axis2.position();
    double ch3=Con1.Axis3.position();
    double ch4=Con1.Axis4.position();
    FL.spin(forward,ch2,percent);
    FR.spin(forward,ch3,percent);
    RL.spin(forward,ch2,percent);
    RR.spin(forward,ch3,percent);

    ML.spin(forward,ch2,percent);
    MR.spin(forward,ch3,percent);

    //This is for the launcher
    Brain.Screen.setCursor(1,1);
    Brain.Screen.print(launch.torque(Nm));
     

    if (toggle){
      launch.spin(forward,100,percent);
      if (Con1.ButtonX.pressing()){
      toggle = false;
      wait(250,msec);
      }
    }
    else{
    if (Con1.ButtonX.pressing()){
      toggle = true;
      wait(250,msec);
    }
    }
    if (toggle == false){
      launch.stop(coast);
    }
    Con1.Screen.setCursor(0,0);
    Con1.Screen.print("Launch: %d, %d%%",toggle,launch.temperature(percent));
    //Con1.Screen.print(launch.temperature(fahrenheit));
    //This is for the arm
    if (Con1.ButtonUp.pressing() == true){
      arm.spin(forward,100,percent);
    }
    else if (Con1.ButtonDown.pressing() == true){
      arm.spin(reverse,100,percent);
    }
    else {
      arm.stop(coast);
    }
if (Con1.ButtonR1.pressing()){
  intake.spin(reverse,100,percent);
}
else if (Con1.ButtonR2.pressing()){
  intake.spin(forward,100,percent);
}
else{
  intake.stop(coast);
}
  if (tog){
    wings.set(true);
    if (Con1.ButtonLeft.pressing()){
      tog = false;
      wait(250,msec);
      }
    }
    else{
    if (Con1.ButtonLeft.pressing()){
      tog = true;
      wait(250,msec);
    }
    }
    if (tog == false){
        wings.set(false);
    }
    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}