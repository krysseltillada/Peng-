#include "TimeInterval.hpp"

TimeInterval::TimeInterval () :
    initial (GetTickCount()) { }

TimeInterval::~TimeInterval () { }

unsigned TimeInterval::getTick () {
    return GetTickCount () - initial;
}
