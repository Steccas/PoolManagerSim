#ifndef ppmSensor_h
#define ppmSensor_h

#include <iostream>
#include "pool.hpp"
#include "sensor.hpp"

using namespace std;

class ppmSensor : sensor
{
public:
    ppmSensor();
    float read();
};

#endif