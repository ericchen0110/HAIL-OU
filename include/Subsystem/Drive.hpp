#pragma once
#include "Global.hpp"

/**
 * @brief Moves for set amount of time at set speed
 * 
 * @param speed speed [-1, 1]
 * @param time time
 */
void moveTime(std::pair<double, double> speed, QTime time);

/**
 * @brief Turns the robot to the desired global angle (using closed-loop control)
 * 
 * @param targetAngle - the target odometry global angle to turn to, normalized to [-pi, pi]
 */
void turnToAngle(QAngle targetAngle);