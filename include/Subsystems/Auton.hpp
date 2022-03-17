#pragma once
#include "main.h"

using AutonRoutine = std::function<void()>;

/**
 * @brief The Auton namespace stores all of our autonomous routines
 * 
 */
namespace Auton {
    /**
     * @brief initializes robot for autonomous
     * 
     */
    void init();

    /**
     * @brief utility function which pulls two mogo from the center using our wings
     * 
     */
    void wingGrab();

    /**
     * @brief our skills autnomous routine
     * 
     */
    void skills();  

    /**
     * @brief Our autonomous routing for starting on the left side
     * 
     */
    void left();

    /**
     * @brief Our autonomous routing for starting on the right side
     * 
     */
    void right();

    /**
     * @brief Our autonomous routine that gets the autonomous win point by ourselves
     * 
     */
    void awp();

    /**
     * @brief LRT Autonomous routine. Route stolen from Chenry (980S)
     * 
     */
    void chenryLRTAuton();
};