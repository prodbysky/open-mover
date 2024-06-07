#pragma once
#include "types.h"

#include <iostream>
#include <random>
#include <string>
#include <type_traits>

namespace ZipLib::Utilities {
    std::string ReadEntireFile(const char* file_name);

    class RNG {
    public:
        RNG() = default;
        void Init();
        template <typename T> T Get(T lower, T upper) {
            // Ensure `lower` <= `upper` to avoid undefined behavior
            if (lower > upper) {
                std::swap(lower, upper);
            }

            if constexpr (std::is_integral<T>::value) {
                std::uniform_int_distribution<T> dist(lower, upper);
                return dist(rng);
            } else if constexpr (std::is_floating_point<T>::value) {
                std::uniform_real_distribution<T> dist(lower, upper);
                return dist(rng);
            }
        }

    private:
        std::mt19937 rng;
    };
} // namespace ZipLib::Utilities
