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
    int time;
    phSensor *phS;
    ppmSensor *ppmS;
    engine *eng;
    void read();
    void startEngine();
    void stopEngine();
public:
    controller(phSensor*, ppmSensor*, engine*, int);
    void manage();
    float getPHReading();
    float getPPMReading();
};

#endif