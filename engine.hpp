#ifndef engine_h
#define engine_h

#include <iostream>
#include "pool.hpp"
#include "sensor.hpp"

using namespace std;

class engine
{
private:
    pool *p;
    float timer;
public:
    engine();
    void clean();
};

#endif