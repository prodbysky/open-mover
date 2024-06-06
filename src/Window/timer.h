#pragma once

#include <Utilities/utilities.h>

namespace ZipLib {
    class Timer {
    private:
        f64 duration;
        bool stopped;

    public:
        Timer() = default;
        Timer(f64 secs);

        void Extend(f64 secs);
        void Trim(f64 secs);

        void Stop();
        void Start();

        void Tick(f64 delta);

        bool Finished();
    };
} // namespace ZipLib
