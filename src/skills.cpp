#include <vex.h>
using namespace vex;
/*
  void autoforward(int speed, float distance, float sleep){
  FL.setVelocity(speed,percent);
  FR.setVelocity(speed,percent);
  RL.setVelocity(speed,percent);
  RR.setVelocity(speed,percent);
  ML.setVelocity(speed,percent);
  MR.setVelocity(speed,percent);

  ML.setBrake(coast);
  MR.setBrake(coast);

  FL.spinFor(distance, rev, false);
  FR.spinFor(distance, rev, false);
  RL.spinFor(distance, rev, false);
  RR.spinFor(distance, rev, false);
  ML.spinFor(distance*0, rev, false);
  MR.spinFor(distance*0, rev, false);

  wait(sleep,sec);
  }
  
  void slide(int speed, float distance){
    //_ is left, _ is right
    FL.setVelocity(speed,percent);
    FR.setVelocity(speed,percent);
    RL.setVelocity(speed,percent);
    RR.setVelocity(speed,percent);

    FL.spinFor(distance, rev, false);
    FR.spinFor(-distance, rev, false);
    RL.spinFor(-distance, rev, false);
    RR.spinFor(distance, rev, true);
  }

  void turn(int speed, float distance, float sleep){
    FL.setVelocity(speed,percent);
    FR.setVelocity(speed,percent);
    RL.setVelocity(speed,percent);
    RR.setVelocity(speed,percent);
    ML.setVelocity(speed,percent);
    MR.setVelocity(speed,percent);

    ML.setBrake(coast);
    MR.setBrake(coast);

    FL.spinFor(distance, rev, false);
    FR.spinFor(-distance, rev, false);
    RL.spinFor(distance, rev, false);
    RR.spinFor(-distance, rev, false);
    ML.spinFor(distance*0, rev, false);
    MR.spinFor(-distance*0, rev, false);

    wait(sleep,sec);
  }
  void marm(float distance,float sleep){
    arm.setVelocity(100,percent);
    arm.spinFor(distance,rev,false);
    wait(sleep,sec);
  }
  void coastbrake(){
    FL.stop(coast);
    FR.stop(coast);
    RL.stop(coast);
    RR.stop(coast);
    ML.stop(coast);
    MR.stop(coast);

  }
  */
  void autolaunch(bool ss){
    if (ss == true){
      launch.spin(forward,100,percent);
    }
    else {
      launch.stop(coast);
    }
  }
  void autounder(int ss){
    if (ss==1){
      launch.spin(forward,1,percent);
    }
    else if (ss==2){
      launch.spin(forward,100,percent);
    }
    else if (ss==0){
      launch.stop(coast);
    }
  }
void skillsauton(){
    autolaunch(true);
}