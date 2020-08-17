#include <iostream>
#include <chrono>
#include <thread>
#include <future>
#include <stdlib.h>
#include <cstdlib>
#include <unistd.h>

#include "pool.hpp"

using namespace std;

pool::pool(float v){
    water = v;
    ph = 7.4;
    ppm = 1.5;
    hiTemp = false;
    //cout << "build\n";
    //this->update();
    //updater = new thread([this]() {update();});
}

void pool::update(){
    //v*12 cloro da mettere
    //diminuisci tot cloro ogni n secondi
    //varia ph 
    for(int i=1; i>0 ; i++) {
        this_thread::sleep_for(chrono::seconds(10));
        //ppm = ppm - 0.2;
        if (!hiTemp) { ppm.store(ppm.load() - 0.1); }
        else
        {
            ppm.store(ppm.load() - 0.2);
        }
        ph.store(ph.load() + 0.1);
        //cout << ppm << endl;
    }
}

float pool::getPH(){return ph.load();}

float pool::getPPM(){return ppm.load();}

void pool::risePH()
{
    float value = 5 * (1 / water);
    ph.store(ph.load() + value);
}

void pool::lowerPH()
{
    ph.store(ph.load - 0.1);
}
