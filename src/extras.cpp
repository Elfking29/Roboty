#include <vex.h>
using namespace vex;
  void autoforward(int speed, float distance, float sleep){
  FL.setVelocity(speed,percent);
  FR.setVelocity(speed,percent);
  RL.setVelocity(speed,percent);
  RR.setVelocity(speed,percent);
  ML.setVelocity(speed,percent);
  MR.setVelocity(speed,percent);

  ML.setBrake(coast);
  MR.setBrake(coast);

  FL.spinFor(-distance, rev, false);
  FR.spinFor(-distance, rev, false);
  RL.spinFor(-distance, rev, false);
  RR.spinFor(-distance, rev, false);
  ML.spinFor(-distance, rev, false);
  MR.spinFor(-distance, rev, false);

  wait(sleep,sec);
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

    FL.spinFor(-distance, rev, false);
    FR.spinFor(distance, rev, false);
    RL.spinFor(-distance, rev, false);
    RR.spinFor(distance, rev, false);
    ML.spinFor(-distance, rev, false);
    MR.spinFor(distance, rev, false);

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
  void mintake(float distance,float sleep){
    intake.setVelocity(100,percent);
    intake.spinFor(distance,rev,false);
    wait(sleep,sec);
  }
   void chicken(bool value, float sleep){
    wings.set(value);
    wait(sleep,sec);
   }