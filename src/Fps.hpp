#pragma once
#ifndef FPS_HEADER
#define FPS_HEADER

#include "TimeInterval.hpp"

class Fps {
public:
    Fps ();
    ~Fps ();

    void update ();

    unsigned getFps ();

private:
    unsigned fpsCount, fpsCounter;
    TimeInterval interval;
};

#endif // FPS_HEADER
