#ifndef engine_h
#define engine_h

#include <iostream>
#include "pool.hpp"
#include "sensor.hpp"

using namespace std;

class engine
{
private:
    pool *pool;
    float power;
    bool isOn;
public:
    engine(pool*, float);
    void clean();
    void start();
    void stop();
};

#endif