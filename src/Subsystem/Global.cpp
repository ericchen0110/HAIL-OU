#include "Global.hpp"

// CONSTANTS
ProfileConstraint moveLimit({4_ftps, 4_ftps2, 27_ftps3});

// CONTROLLER(s)
Controller master(ControllerId::master);

// MOTORS
MotorGroup leftChassis({1, -2, 3, -4});
MotorGroup rightChassis({-5, 6, -7, 8});
MotorGroup climb({-11, 12});

// PNEUMAICS
Solenoid leftWing('A'); // TODO: Change Port
Solenoid rightWing('B'); // TODO: Change Port
Solenoid intake('C'); // TODO: Change Port

// SENSORS
IMU imu(13);

// SUBSYSTEM CONTROLLERS
std::shared_ptr<ChassisController> chassis = ChassisControllerBuilder()
	.withMotors({1, -2, 3, -4}, {-5, 6, -7, 8}) 
	.withDimensions({AbstractMotor::gearset::blue, 59.0/39.0}, {{3.25_in, 10_in}, imev5BlueTPR}) 
	.build();

std::shared_ptr<AsyncMotionProfiler> profiler = AsyncMotionProfilerBuilder()
	.withOutput(chassis)
	.withProfiler(std::make_unique<SCurveMotionProfile>(moveLimit))
	.build();

std::shared_ptr<IterativePosPIDController> turnPID = std::make_shared<IterativePosPIDController>(
	0.06, 0.005, 0.00115, 0, TimeUtilFactory::withSettledUtilParams(2, 2, 100_ms)
);

std::shared_ptr<AsyncPositionController<double, double>> climbController = AsyncPosControllerBuilder()
	.withMotor({-11, 12})
	.withGearset(AbstractMotor::GearsetRatioPair({AbstractMotor::gearset::red, 60.0/12.0}))
	.build();

// DISPLAY
void createBlankBackground(){
    lv_obj_t *background;
    lv_style_t backgroundStyle;
    lv_style_copy(&backgroundStyle, &lv_style_plain);
    backgroundStyle.body.main_color = LV_COLOR_BLACK;
    backgroundStyle.body.grad_color = LV_COLOR_BLACK;
    backgroundStyle.body.radius = 0;
    backgroundStyle.text.color = LV_COLOR_WHITE;
    background = lv_obj_create(lv_scr_act(), NULL);
    lv_obj_set_free_num(background, 0);
    lv_obj_set_style(background, &backgroundStyle);
    lv_obj_set_size(background, LVGL_SCREEN_WIDTH, LVGL_SCREEN_HEIGHT);
    lv_obj_align(background, NULL, LV_ALIGN_CENTER, 0, 0);
}