#pragma once
#ifndef TIME_INTERVAL_HEADER
#define TIME_INTERVAL_HEADER

#include <windows.h>

class TimeInterval {
public:
    TimeInterval ();
    ~TimeInterval ();

    unsigned getTick ();

private:
    unsigned initial;
};


#endif // TIME_INTERVAL_HEADER
