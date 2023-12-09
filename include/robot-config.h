using namespace vex;

extern brain Brain;
extern controller Con1;

extern motor FL;
extern motor FR;
extern motor RL;
extern motor RR;

extern motor ML;
extern motor MR;

extern motor launch;

extern motor intake;

extern rotation rot;

extern motor arm;

extern digital_in left_button;
extern digital_in right_button;

extern digital_out wings;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);