#pragma once
#include "okapi/api.hpp"
#include "ryanlib/api.hpp"

using namespace ryan;
using namespace okapi;

// CONSTANTS
const double DEADBAND = 0.0500;

constexpr int LVGL_SCREEN_WIDTH = 480;
constexpr int LVGL_SCREEN_HEIGHT = 240;

constexpr double LIFT_READY_POSITION = 800; // TODO: TUNE
constexpr double LIFT_CLIMB_POSITION = 300; // TODO: TUNE

extern ProfileConstraint moveLimit;

// CONTROLLER(s)
extern Controller master;

// MOTORS
extern MotorGroup leftChassis;
extern MotorGroup rightChassis;
extern MotorGroup climb;

// PNEUMAICS
extern Solenoid leftWing;
extern Solenoid rightWing;
extern Solenoid intake;

// SENSORS
extern IMU imu;

// SUBSYSTEM CONTROLLERS
extern std::shared_ptr<ChassisController> chassis;
extern std::shared_ptr<AsyncMotionProfiler> profiler;
extern std::shared_ptr<IterativePosPIDController> turnPID;
extern std::shared_ptr<AsyncPositionController<double, double>> climbController;

/**
 * @brief Create a Blank Background using LVGL
 * 
 */
void createBlankBackground();
