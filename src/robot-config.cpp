#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;
controller Con1;
// Ports 1 & 3 are broken
motor FL(PORT2,ratio18_1,false);
motor FR(PORT14,ratio18_1,true);
motor RL(PORT4,ratio18_1,false);
motor RR(PORT5,ratio18_1,true);

motor ML(PORT6,ratio18_1,true);
motor MR(PORT7,ratio18_1,false);

motor launch(PORT8,ratio36_1,true);

motor intake(PORT9,ratio18_1,true);

rotation rot(PORT16);
motor arm(PORT20,ratio36_1,false);

digital_in right_button(Brain.ThreeWirePort.B);
digital_in left_button(Brain.ThreeWirePort.C);

digital_out wings(Brain.ThreeWirePort.F);
/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  // Nothing to initialize
}