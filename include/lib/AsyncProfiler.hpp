#pragma once
#include "main.h"

/**
 * @brief an enum containing all possible states for our motion profile controller
 * 
 */
enum class MotionProfileState{
    MOVE, FOLLOW, IDLE
};

// forward declare
template class StateMachine<MotionProfileState>;

/**
 * @brief class that allows us to control our chassis asynchronously using motion profiles
 * 
 */
class AsyncMotionProfiler : public StateMachine<MotionProfileState, MotionProfileState::IDLE>, public TaskWrapper {
    protected:
    AsyncMotionProfiler(std::shared_ptr<ChassisController> iChassis, 
                        std::unique_ptr<LinearMotionProfile> iMove, 
                        std::unique_ptr<FFVelocityController> iLeftLinear, 
                        std::unique_ptr<FFVelocityController> iRightLinear,
                        std::unique_ptr<FFVelocityController> iLeftTrajectory,
                        std::unique_ptr<FFVelocityController> iRightTrajectory,
                        const TimeUtil& iTimeUtil);

    void operator=(const AsyncMotionProfiler& rhs) = delete;

    friend class AsyncMotionProfilerBuilder;

    public:

    void setTarget(QLength iDistance);

    void setTarget(const Trajectory& iPath);

    void stop();

    void loop() override;

    void waitUntilSettled();

    protected:
    std::shared_ptr<ChassisController> chassis;
    std::shared_ptr<AbstractMotor> leftMotor;
    std::shared_ptr<AbstractMotor> rightMotor;

    std::unique_ptr<LinearMotionProfile> profiler;
    std::unique_ptr<FFVelocityController> leftLinear;
    std::unique_ptr<FFVelocityController> rightLinear;
    std::unique_ptr<FFVelocityController> leftTrajectory;
    std::unique_ptr<FFVelocityController> rightTrajectory;

    TimeUtil timeUtil;
    std::unique_ptr<AbstractRate> rate;
    std::unique_ptr<AbstractTimer> timer;
    QTime maxTime{0.0};

    Trajectory path;
    pros::Mutex lock;
};


/**
 * @brief An AsyncMotionProfile builder class which allows more intuitive instantiation of the class
 * 
 */
class AsyncMotionProfilerBuilder{
    public:
    /**
     * @brief Constructs a new Async Motion Profiler Builder object
     * 
     */
    AsyncMotionProfilerBuilder();

    /**
     * @brief Destroys the Async Motion Profiler Builder object
     * 
     */
    ~AsyncMotionProfilerBuilder() = default;

    /**
     * @brief sets the chassis object for the profiler to output to
     * 
     * @param iChassis the chassis object to output to
     * @return AsyncMotionProfilerBuilder& an ongoing builder
     */
    AsyncMotionProfilerBuilder& withOutput(std::shared_ptr<ChassisController> iChassis);

    /**
     * @brief sets the motion profile generator to use for linear movements
     * 
     * @param iProfiler the profile generator
     * @return AsyncMotionProfilerBuilder& 
     */
    AsyncMotionProfilerBuilder& withProfiler(std::unique_ptr<LinearMotionProfile> iProfiler);

    /**
     * @brief sets the motor controller to use for linear movements
     * 
     * @param iLeft 
     * @param iRight 
     * @return AsyncMotionProfilerBuilder& 
     */
    AsyncMotionProfilerBuilder& withLinearController(FFVelocityController iLeft, FFVelocityController iRight);

    /**
     * @brief sets the motor controller to use when following paths    
     * 
     * @param iLeft 
     * @param iRight 
     * @return AsyncMotionProfilerBuilder& 
     */
    AsyncMotionProfilerBuilder& withTrajectoryController(FFVelocityController iLeft, FFVelocityController iRight);

    /**
     * @brief builds the async motion profiler object with the specified parameters. The thread is started automaically
     * 
     * @return std::shared_ptr<AsyncMotionProfiler> the built async motion profiler
     */
    std::shared_ptr<AsyncMotionProfiler> build();

    private:
    std::unique_ptr<LinearMotionProfile> profile;
    std::shared_ptr<ChassisController> chassis;
    FFVelocityController leftL;
    FFVelocityController rightL;
    FFVelocityController leftT;
    FFVelocityController rightT;

    bool linearInit = false;
    bool trajInit = false;
    bool driveInit = false;
    bool profileInit = false;
};