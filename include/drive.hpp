#ifndef DRIVE_GUARD
#define DRIVE_GUARD

#include "main.h"

using namespace okapi;

namespace drive
{
    enum driveStates
    {
        notRunning = 'x',
        running = 'r',
        yield = 'y'
    };

    extern driveStates currStates;

    extern Motor driveR1, driveR2, driveL1, driveL2;
    extern std::shared_ptr<OdomChassisController> chassis;
    extern void update();

    extern void act(void *);
} // namespace drive

#endif