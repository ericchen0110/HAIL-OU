#include "main.h"

void initialize(){
	pros::lcd::initialize();
	imu.calibrate();
}

void disabled(){}

void competition_initialize(){}

void autonomous(){
    // Auton::init();
    // Auton::skills();
    // Auton::match();
    Auton::test();
}

void opcontrol(){
	// Starts logo gif
    createBlankBackground();
    std::unique_ptr<Gif> gif = std::make_unique<Gif>("/usd/gif/crab-rave.gif", lv_scr_act());

	auto model = chassis->getModel();
	while(true){
		model->tank(master.getAnalog(ControllerAnalog::leftY), 
					master.getAnalog(ControllerAnalog::rightY), 
					0.05);

		if(master.getDigital(ControllerDigital::R1)){
			climbController->setTarget(0);
		}

		if(master.getDigital(ControllerDigital::R2)){
			climbController->setTarget(1000);
		}	

		pros::delay(10);
    }
}
