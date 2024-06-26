#ifndef ROTATION_HPP
#define ROTATION_HPP

#include "sensors/LSM6DS33.hpp"
#include "sensors/LPS25H.hpp"
#include "sensors/magnetometer.hpp"

struct Imu
{
    float pitch = 0;
    float yaw = 0;
    float roll = 0;
    float preassure = 0;
    float altitude = 0;

    Vec3<float> accel{};
    Vec3<float> velocity{};

    // TODO: implement

    Vec3<float> accelAvg[25];
    uint16_t counter = 0;

    void calibrate();
    void update();
    void readings();
    Imu();

    LSM6DS33 imu;              // Accelerometer and Gyroscope
    Magnetometer magnetometer; // Magnetometer
    LPS25H barometer;          // Barometer
private:
    // sensor readings
    float filtered_pitch = 0;
    Vec3<float> gyro{};
    Vec3<int16_t> mag{};

    void appendAccel();
    Vec3<float> getAccel();

    void calculateRollAndPitch();
    void calculateYaw();
    void calculateAlltitude();
};

#endif

/*

    yaw
     | y
     |
     |
     |          x
    /------------ pitch
   /
  /
 /  z
roll

*/