#ifndef LIS3MDL_HPP
#define LIS3MDL_HPP

#include <LIS3MDL.h>

struct Magnetometer
{
    enum class Scale : uint8_t
    {
        gauss4,
        gauss8,
        gauss12,
        gauss16,
    };

    using Data = std::array<float, 3>;

    Magnetometer();
    Data readMag();
    void compass();

private:
    LIS3MDL mag;
};

#endif // LIS3MDL_HPP
