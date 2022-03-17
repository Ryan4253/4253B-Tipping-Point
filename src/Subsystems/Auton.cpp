#include "main.h"

void Auton::init() {
    // sets brake mode
    leftDrive.setBrakeMode(AbstractMotor::brakeMode::hold);
    rightDrive.setBrakeMode(AbstractMotor::brakeMode::hold);
    lift.setBrakeMode(AbstractMotor::brakeMode::hold);

    // resets lift controller
    liftController->reset();
    
}

void Auton::wingGrab() {
    wings.set(true);
    profiler->setTarget(-2.75_ft);
    pros::delay(775);
    wings.set(false);
    profiler->waitUntilSettled();

    profiler->setTarget(3.5_ft);
    profiler->waitUntilSettled();
    wings.set(true); pros::delay(500); wings.set(false); pros::delay(500);
}

void Auton::chenryLRTAuton(){
    // pushes right yellow mogo into far home zone, drive back
    profiler->setTarget(7_ft, true);
    profiler->setTarget(-5.35_ft, true);

    // grab alliance mogo
    turnToAngle(-90_deg);
    profiler->setTarget(-1.25_ft, true);
    mogoClamp.set(true); pros::delay(250); mogo.set(true);

    // pushes center mogo to far home zone, score rings in alliance mogo
    profiler->setTarget(1.5_ft);
    roller.moveVoltage(12000);
    profiler->waitUntilSettled();
    turnToAngle(-45_deg);
    roller.moveVoltage(0);
    profiler->setTarget(8_ft, true);
    
    // push left yellow mogo to close home zone
    profiler->setTarget(-0.5_ft, true);
    turnToAngle(180_deg);
    profiler->setTarget(Match::chenryLRTPath1, true);
}

void Auton::left(){
    liftController->setTarget(100);
    mogoClamp.set(true); pros::delay(250); mogo.set(true);
    profiler->setTarget(Skills::path0);
    pros::delay(1000);
    liftController->setTarget(0);
    roller.moveVoltage(12000);
    profiler->waitUntilSettled();
    claw.set(true);

    // drive forward, deposit first yellow
    profiler->setTarget(2 * okapi::tile);
    profiler->waitUntilSettled();
    //liftController->setTarget(0);
    claw.set(false);

    // get center mogo
    profiler->setTarget(-0.5_tile);
    profiler->waitUntilSettled();
    turnToAngle(-128_deg);
    profiler->setTarget(8_in);
    profiler->waitUntilSettled();

    profiler->setTarget((1.5_tile) + (6_in));
    profiler->waitUntilSettled();
    profiler->setTarget(-6_in);
    profiler->waitUntilSettled();

    turnToAngle(135_deg);
    profiler->setTarget(1_tile);
    profiler->waitUntilSettled();
    claw.set(true);
    mogo.set(false);
    profiler->setTarget(-42_in);
    profiler->waitUntilSettled();
    
}

void Auton::right(){
    wingGrab();
    
    profiler->setTarget(-1.75_ft);
    profiler->waitUntilSettled();
    turnToAngle(90_deg);

    profiler->setTarget(-3_ft);
    profiler->waitUntilSettled();
    mogoClamp.set(true); pros::delay(250); mogo.set(true);

    profiler->setTarget(6_in);
    liftController->setTarget(710);
    profiler->waitUntilSettled();
    turnToAngle(180_deg);

    roller.moveVoltage(12000);
    profiler->setTarget(3_ft);
    profiler->waitUntilSettled();
    profiler->setTarget(-3_ft);
    profiler->waitUntilSettled();
    turnToAngle(0_deg);
    
    // oscillate match load
    for(int i = 0; i < 3; i++) {
        profiler->setTarget(2_ft);
        profiler->waitUntilSettled();
        profiler->setTarget(-2_ft);
        profiler->waitUntilSettled();
    }
}

void Auton::awp(){
    wingGrab();

    turnToAngle(0_deg);
    profiler->setTarget(-1.6_ft);
    profiler->waitUntilSettled();
    turnToAngle(90_deg);

    profiler->setTarget(-3_ft);
    profiler->waitUntilSettled();

    mogoClamp.set(true); pros::delay(250); mogo.set(true);

    profiler->setTarget(9_ft);
    roller.moveVoltage(12000); pros::delay(125); roller.moveVoltage(0);
    pros::delay(750);
    mogoClamp.set(false); mogo.set(false);
    roller.moveVoltage(0);
    profiler->waitUntilSettled();
    
    profiler->setTarget(-2_ft);
    profiler->waitUntilSettled();
    turnToAngle(90_deg);
    profiler->setTarget(2_ft);
    profiler->waitUntilSettled();
    profiler->setTarget(-1_ft);
    profiler->waitUntilSettled();
    
    turnToAngle(140_deg);
    profiler->setTarget(-2_ft);
    profiler->waitUntilSettled();

    mogoClamp.set(true); pros::delay(250); mogo.set(true);

    turnToAngle(90_deg);
    profiler->setTarget(1.5_ft);
    profiler->waitUntilSettled();
}

void Auton::skills(){
    // Get 1st Mogo
    liftController->setTarget(100);
    mogoClamp.set(true); pros::delay(250); mogo.set(true);
    roller.moveVoltage(12000);
    profiler->setTarget(Skills::path0);
    pros::delay(1000);
    liftController->setTarget(0);
    profiler->waitUntilSettled();
    claw.set(true);
    
    // Drive to platform, score mogo
    profiler->setTarget(Skills::path1);
    liftController->setTarget(710);
    profiler->waitUntilSettled();
    turnToAngle(70_deg);
    turnToAngle(90_deg);
    claw.set(false);
    liftController->setTarget(MAX_LIFT_HEIGHT);
    pros::delay(500);

    // Drive back, drive to side alliance mogo
    profiler->setTarget(-8_in, true);
    turnToAngle(0_deg);
    liftController->setTarget(0);
    profiler->setTarget((2_tile)+(2_in));
    pros::delay(550);
    mogoClamp.set(false);
    profiler->waitUntilSettled();
    pros::delay(100);
    claw.toggle();

    // Drive to center mogo, push to end
    liftController->setTarget(100);
    profiler->setTarget((-0.7_tile)+(2_in), true);
    turnToAngle(45_deg);
    mogo.toggle();
    profiler->setTarget(-1.8_tile, true);
    profiler->setTarget(-6.5_ft, true);

    // score red side mogo
    liftController->setTarget(MAX_LIFT_HEIGHT);
    profiler->setTarget(Skills::path4, true);
    claw.set(false);
    profiler->setTarget(-5.75_in, true);
    liftController->setTarget(0);
    turnToAngle(0_deg);

    // grab side blue mogo
    profiler->setTarget((-4.5_ft), true);
    pros::delay(300);
    mogoClamp.set(true);
    pros::delay(100);
    mogo.set(true);

    // grab right side yellow
    turnToAngle(65_deg);
    profiler->setTarget(80_cm);
    liftController->setTarget(100);
    pros::delay(800);
    liftController->setTarget(0);
    profiler->waitUntilSettled();
    claw.set(true);
    
    // score right side yellow
    profiler->setTarget(Skills::path5);
    pros::delay(100);
    liftController->setTarget(MAX_LIFT_HEIGHT);
    profiler->waitUntilSettled();
    claw.set(false);
    pros::delay(300);

    // score dropped blue mogo
    profiler->setTarget(-6_in, true);
    liftController->setTarget(0);
    turnToAngle(0_deg);
    profiler->setTarget(1.2_tile);
    pros::delay(150);
    mogoClamp.set(false);
    profiler->waitUntilSettled();
    pros::delay(100);
    claw.set(true);
    liftController->setTarget(MAX_LIFT_HEIGHT);
    pros::delay(1000);
    turnToAngle(90_deg);
    profiler->setTarget(6_in, true);
    claw.set(false);
    
    // grab other blue alliance
    profiler->setTarget(-6_in, true);
    liftController->setTarget(0);
    turnToAngle(-180_deg);
    profiler->setTarget(1_tile, true);
    pros::delay(100);
    claw.set(true);
}


