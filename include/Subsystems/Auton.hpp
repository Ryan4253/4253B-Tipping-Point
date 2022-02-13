#pragma once
#include "main.h"

using AutonFunction = std::function<void()>;

/**
 * @brief This namespaces contains our auton selector implemented
 *        using the V5 controller, as well as all our auton routes
 * 
 */
namespace Auton {
    extern std::map<std::string, AutonFunction> auton;
    extern std::map<int, std::string> name;
    extern std::string currentName;
    extern int index;

    /**
     * @brief Adds a new autonomous routine to our selector
     * 
     * @param iAutonomous the autonomous function
     * @param iName name of the autonomous
     */
    void add(std::function<void()> iAutonomous, std::string iName);

    /**
     * @brief switched selected auton to the next option
     * 
     */
    void switchAuton();

    /**
     * @brief sets the routine to the current autonomous
     * 
     */
    void select();

    /**
     * @brief executes the selected autonomous
     * 
     */
    void execute();

    /**
     * @brief Get the name of the currently candidate autonomous
     * 
     * @return std::string the name of the autonomous that will be set of select() is called
     */
    std::string getCandidateName();

    /**
     * @brief Get the name of the currently selected autonomous
     * 
     * @return std::string the name of the autonomous that will be run if execute() is called
     */
    std::string getSelectedName();

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

    void chenryLRTAuton();
};