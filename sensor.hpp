#ifndef sensor_h
#define sensor_h

#include <iostream>
#include "pool.hpp"

using namespace std;

class sensor
{
protected:
    pool *p;
public:
    sensor();
    virtual float read();
};

#endif