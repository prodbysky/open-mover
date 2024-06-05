#include "timer.h"

namespace ZipLib {
    Timer::Timer(f64 secs) {
        duration = secs;
        stopped  = true;
    }

    void Timer::Start() { stopped = false; }
    void Timer::Stop() { stopped = true; }

    void Timer::Extend(f64 secs) { duration += secs; }
    void Timer::Trim(f64 secs) { duration -= secs; }

    void Timer::Tick(f64 delta) {
        if (!stopped && duration > 0) {
            duration -= delta;
            stopped   = true;
        }
    }

    bool Timer::Finished() { return duration <= 0; }
} // namespace ZipLib
