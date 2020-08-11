#ifndef phSensor_h
#define phSensor_h

#include <iostream>
#include "pool.hpp"
#include "sensor.hpp"

using namespace std;

class phSensor : sensor
{
public:
    phSensor();
    float read();
};

#endif