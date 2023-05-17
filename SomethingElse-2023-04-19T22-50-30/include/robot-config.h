using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor rightmotor;
extern motor leftmotor;
extern inertial Inertial;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );