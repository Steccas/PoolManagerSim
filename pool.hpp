#ifndef pool_h
#define pool_h

#include <future>
#include <iostream>
#include <thread>

using namespace std;

class pool
{
private:
    //water *w;
    bool hiTemp;
    float water;
    atomic<float> ph;
    atomic<float> ppm;
    thread* updater;
public:
    pool(float);
    void update();
    float getPH();
    float getPPM();
    void risePH();
    void risePPM();
    void lowerPH();
};

#endif