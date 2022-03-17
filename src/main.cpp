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
}

void disabled(){}

void competition_initialize(){}

void autonomous(){
    Auton::init();
    Auton::chenryLRTAuton();
}

void opcontrol(){
    // Starts logo gif
    createBlankBackground();
    std::unique_ptr<Gif> gif = std::make_unique<Gif>("/usd/gif/crab-rave.gif", lv_scr_act());

    // Disable Lift Task
    liftController->flipDisable(true);
    bool rollerState = true;

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
        curvatureDrive(driveCurve(power), 0.5 * curvature, power == 0);

        /**
         * @brief lift control using an async PID controller
         *        L1 pressed: increments target angle by LIFT_STEP
         *        L2 pressed: decrements target angle by LIFT_STEP
         *        note: target angle is capped to [0, MAX_LIFT_HEIGHT] to protect the lift
         */
        if(master.getDigital(ControllerDigital::L1) && master.getDigital(ControllerDigital::L2)) {
            lift.moveVoltage(0);
        } else if(master.getDigital(ControllerDigital::L1)) {
            lift.moveVoltage(12000);
        } else if(master.getDigital(ControllerDigital::L2)) {
            lift.moveVoltage(-12000);
        } else {
            lift.moveVoltage(0);
        }

        /**
         * @brief controls the claw depending on the button value 
         *        When R1 is pressed: claw solenoid is set to true
         *        When R2 is unpressed: claw solenoid is set to false
         */
        claw.set(master.getDigital(ControllerDigital::R1));

        if(master[ControllerDigital::X].changedToPressed()){
            roller.moveVelocity(rollerState * 600);
            rollerState = !rollerState;
        }

        /**
         * @brief controls the mogo holder pistons using rising edge detection (上升緣觸發)
         *        When X is pressed: toggles the state of the mogo solenoid
         */
        if(master[ControllerDigital::Y].changedToPressed()){
            mogoClamp.toggle();
        }

        /**
         * @brief controls the mogo clamp pistons using rising edge detection (上升緣觸發)
         *        When R2 is pressed: toggles the state of the mogo clamp
         */
        if(master[ControllerDigital::R2].changedToPressed()){
            if(mogoClamp.getState() == false){
                mogoClamp.toggle();
                pros::delay(250);
                mogo.toggle();
            }
            else{
                mogo.toggle();
                pros::delay(250);
                mogoClamp.toggle();
            }
        }

        pros::delay(10);
    }
}
