#include "main.h"

using namespace okapi;

namespace drive
{
    driveStates currState;

    std::shared_ptr<OdomChassisController> chassis =
        ChassisControllerBuilder()
            .withMotors((DRIVE_L1, DRIVE_L2), (DRIVE_R1, DRIVE_R2)) // left motor is 1, right motor is 2 (reversed)
            // green gearset, 4 inch wheel diameter, 11.5 inch wheelbase
            .withDimensions(AbstractMotor::gearset::green, {{4_in, 11.5_in}, imev5GreenTPR})
            // left encoder in ADI ports A & B, right encoder in ADI ports C & D (reversed)
            .withSensors(ADIEncoder{SPORT_RTOP, SPORT_RBOT}, ADIEncoder{SPORT_LTOP, SPORT_LBOT, true}, ADIEncoder{SPORT_MTOP, SPORT_MBOT})
            // specify the tracking wheels diameter (2.75 in), track (7 in), and TPR (360)
            .withOdometry({{2.75_in, 7_in}, quadEncoderTPR}, StateMode::FRAME_TRANSFORMATION)
            .buildOdometry();

} // namespace drive