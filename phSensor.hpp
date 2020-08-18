#ifndef phSensor_h
#define phSensor_h

#include <iostream>
#include "pool.hpp"
#include "sensor.hpp"

using namespace std;

class phSensor : public sensor
{
public:
    phSensor(pool*);
    float read() override;
};

#endif