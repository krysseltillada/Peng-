#include "Fps.hpp"

Fps::Fps () :
    fpsCount (0), fpsCounter (0) { }

Fps::~Fps () { }

void Fps::update () {
    ++fpsCount;

    if (interval.getTick () > 1000) {
        fpsCounter = fpsCount;
        fpsCount = 0;
        interval = TimeInterval ();
    }

}

unsigned Fps::getFps () {
    return fpsCounter;
}


