#include "main.h"

std::map<std::string, AutonFunction> Auton::auton;
std::map<int, std::string> Auton::name;
std::string Auton::currentName = "";
int Auton::index = 0;


void Auton::add(AutonFunction iAutonomous, std::string iName){
    auton.insert(make_pair(iName, iAutonomous));
    name.insert(make_pair(auton.size(), iName));
}

void Auton::switchAuton(){
    if(auton.size() == 0){
        return;
    }
    index++;
    index %= auton.size();
}

void Auton::select(){
    if(auton.size() == 0){
        return;
    }
    std::ofstream file("/usd/auton.txt", std::ios::out);
    
    file << getCandidateName();
}

std::string Auton::getCandidateName(){
    if(auton.size() == 0){
        return "";
    }
    auto ret = name.find(index);
    return ret->second;
}

std::string Auton::getSelectedName(){
    return currentName;
}

void Auton::execute(){
    std::ifstream file("/usd/auton.txt", std::ios::in);
    if(file.peek() == std::ifstream::traits_type::eof()){
        return;
    }

    std::string autonName; file >> autonName;

    auto it = auton.find(autonName);

    if(it == auton.end()){
        return;
    }

    it->second();
}

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

void Auton::chenryLRTAuton() {
    profiler->setTarget(7_ft, true);

    profiler->setTarget(-5.35_ft, true);

    turnToAngle(-90_deg);

    profiler->setTarget(-1.25_ft, true);

    mogoClamp.set(true); pros::delay(250); mogo.set(true);

    profiler->setTarget(1.5_ft);
    roller.moveVoltage(12000);
    profiler->waitUntilSettled();

    turnToAngle(-45_deg);

    roller.moveVoltage(0);

    profiler->setTarget(8_ft, true);
    
    profiler->setTarget(-0.5_ft, true);

    turnToAngle(180_deg);

    profiler->setTarget(Match::chenryLRTPath1, true);

    // profiler->setTarget(4_ft);
    // profiler->waitUntilSettled();

    // profiler->setTarget(-3.5_ft);
    // profiler->waitUntilSettled();
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
    //liftController->setTarget(200);

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
    profiler->setTarget(-8_in);
    profiler->waitUntilSettled();
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
    profiler->setTarget((-0.7_tile)+(2_in));
    profiler->waitUntilSettled();
    turnToAngle(45_deg);
    mogo.toggle();
    profiler->setTarget(-1.8_tile);
    profiler->waitUntilSettled();
    profiler->setTarget(-6.5_ft);
    profiler->waitUntilSettled();

    // score red side mogo
    liftController->setTarget(MAX_LIFT_HEIGHT);
    profiler->setTarget(Skills::path4);
    profiler->waitUntilSettled();
    claw.set(false);
    profiler->setTarget(-5.75_in);
    profiler->waitUntilSettled();
    liftController->setTarget(0);
    turnToAngle(0_deg);

    // grab side blue mogo
    profiler->setTarget((-4.5_ft));
    profiler->waitUntilSettled();
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
    //profiler->setTarget(148_cm);
    profiler->setTarget(Skills::path5);
    pros::delay(100);
    liftController->setTarget(MAX_LIFT_HEIGHT);
    profiler->waitUntilSettled();
    claw.set(false);
    pros::delay(300);

    // score dropped blue mogo
    profiler->setTarget(-6_in);
    profiler->waitUntilSettled();
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
    profiler->setTarget(6_in);
    profiler->waitUntilSettled();
    claw.set(false);
    
    // grab other blue alliance
    profiler->setTarget(-6_in);
    profiler->waitUntilSettled();
    liftController->setTarget(0);
    turnToAngle(-180_deg);
    profiler->setTarget(1_tile);
    profiler->waitUntilSettled();
    pros::delay(100);
    claw.set(true);
}


