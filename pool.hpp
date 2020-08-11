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
    float water;
    float ph;
    float ppm;
    thread updater;
public:
    pool(float);
    void update();
    float getPH();
    float getPPM();
};

#endif