#ifndef ppmSensor_h
#define ppmSensor_h

#include <iostream>
#include "pool.hpp"
#include "sensor.hpp"

using namespace std;

class ppmSensor : public sensor
{
public:
    ppmSensor(pool*);
    float read() override;
    void injectChlorine();
};

#endif