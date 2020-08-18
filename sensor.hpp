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
    sensor(pool*);
    virtual float read() = 0;
};

#endif