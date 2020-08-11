#include <iostream>
#include <chrono>
#include <thread>
#include <future>

#include "pool.hpp"

using namespace std;

pool::pool(float v){
    water = v;
    ph = 7.4;
    ppm = 1.0;
    updater = thread(&pool::update, this);
}

void pool::update(){
    //diminuisci tot cloro ogni n secondi
    //varia ph
    this_thread::sleep_for(10s);
    cout << "Prova";
}

float pool::getPH(){return ph;}

float pool::getPPM(){return ppm;}