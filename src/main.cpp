#include "main.h"

void initialize(){
    // Screen initialization
	pros::lcd::initialize();

    // Vision initialization
    pros::vision_signature_s_t RED_SIG = pros::Vision::signature_from_utility(1, 5685, 8135, 6910, -1963, -1705, -1834, 4.000, 0);
    vision_sensor.set_signature(1, &RED_SIG);

    // IMU initialization
    pros::lcd::set_text(2, "imu calibrating..............");
    imu.calibrate();
    pros::delay(3000);
    pros::lcd::set_text(2, "imu calibrated");

    // Adds autonomous functions
    Auton::add([](){}, "Do Nothing");
    Auton::add(Auton::skills, "Skills");
    Auton::add(Auton::right, "Right Wing");
    Auton::add(Auton::awp, "AWP Wing");
}

void disabled(){}

void competition_initialize(){}

void autonomous(){
    Auton::execute();
}

void opcontrol(){
    Auton::init();
    Auton::skills();
    while(true){
        pros::delay(10);
    }

    // Starts logo gif
    createBlankBackground();
    Gif gif("/usd/gif/logo.gif", lv_scr_act());

    // Initializes variable
    int liftPos = 0;

    // Disable Lift Task
    //liftController->flipDisable();

    // Sets motor brake mode
    leftDrive.setBrakeMode(AbstractMotor::brakeMode::coast);
    rightDrive.setBrakeMode(AbstractMotor::brakeMode::coast);
    lift.setBrakeMode(AbstractMotor::brakeMode::hold);

    while(true){
        /**
         * @brief chassis control using our custom curvature mode
         *        Left analog stick: throttle
         *        right analog stick: curvature
         */
        double power = Math::deadband(master.getAnalog(ControllerAnalog::leftY), DEADBAND);
        double curvature = Math::deadband(master.getAnalog(ControllerAnalog::rightX), DEADBAND);
        curvatureDrive(power, curvature, power == 0);

        /**
         * @brief lift control using an async PID controller
         *        L1 pressed: increments target angle by LIFT_STEP
         *        L2 pressed: decrements target angle by LIFT_STEP
         *        note: target angle is capped to [0, MAX_LIFT_HEIGHT] to protect the lift
         */
        liftPos += LIFT_STEP * master.getDigital(ControllerDigital::L1); 
        liftPos -= LIFT_STEP * master.getDigital(ControllerDigital::L2);
        liftController->setTarget(liftPos = Math::clamp(liftPos, 0, MAX_LIFT_HEIGHT));

        /**
         * @brief controlls our roller
         *        When both L1 and L2 pressed: runs the roller inward (intakes)
         *        When A is pressed: runs the roller outward (outtakes)
         *        When Both are pressed / unpressed: no movement
         */
        roller.moveVoltage(12000*((master.getDigital(ControllerDigital::L1) && master.getDigital(ControllerDigital::L2))-master.getDigital(ControllerDigital::A)));

        /**
         * @brief controls the claw depending on the button value 
         *        When R1 is pressed: claw solenoid is set to true
         *        When R2 is unpressed: claw solenoid is set to false
         */
        claw.set(master.getDigital(ControllerDigital::R1));

        /**
         * @brief controls the wing depending on the button value 
         *        When Y is pressed: wing solenoid is set to true
         *        When Y is unpressed: wing solenoid is set to false
         */
        wings.set(master.getDigital(ControllerDigital::Y));

        /**
         * @brief controls the mogo holder pistons using rising edge detection (上升緣觸發)
         *        When X is pressed: toggles the state of the mogo solenoid
         */
        if(master[ControllerDigital::X].changedToPressed()){
            mogo.toggle();
        }

        /**
         * @brief controls the mogo clamp pistons using rising edge detection (上升緣觸發)
         *        When R2 is pressed: toggles the state of the mogo clamp
         */
        if(master[ControllerDigital::R2].changedToPressed()){
            mogoClamp.toggle();
        }

        /**
         * @brief switches the desired autnomous if right is pressed
         */
        if(master[ControllerDigital::right].changedToPressed()){
            Auton::switchAuton();
        }

        /**
         * @brief writes the desired autonomous to the SD Card if left is pressed
         */
        if(master[ControllerDigital::left].changedToPressed()){
            Auton::select();
        }

        pros::delay(10);
    }
}
