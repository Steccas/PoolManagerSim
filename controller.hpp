#ifndef controller_h
#define controller_h

#include <iostream>
#include "phSensor.hpp"
#include "ppmSensor.hpp"
#include "engine.hpp"

using namespace std;

class controller
{
private:
    float ph;
    float ppm;
    //pool *p;
    phSensor *phS;
    ppmSensor *ppmS;
    engine *eng;
public:
    controller(phSensor*, ppmSensor*, engine*);
    void read();
    void startEngine();
    void stopEngine();
};

#endif