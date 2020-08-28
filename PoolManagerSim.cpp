#include <cstdlib>
#include <cstdio>
#include <random>
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <unistd.h>

#include "pool.hpp"
#include "engine.hpp"
#include "controller.hpp"
#include "phSensor.hpp"
#include "ppmSensor.hpp"

using namespace std;

pool* p;

engine* e;

controller* c;

phSensor* phs;

ppmSensor* ppms;

void updatePool();

void showStats();

void reader();

void engineOperation();

void controllerOperation();

void inputManager();

void swim();

void setTemp();

int main(int argc, char **argv)
{
    if (argc == 2) {
        cout << "Starting..." << endl;
        p = new pool(atof(argv[1]));
        e = new engine(p, 4);
        phs = new phSensor(p);
        ppms = new ppmSensor(p);
        c = new controller(phs, ppms, e, 2);
        thread tPool(updatePool);
        thread tEngine(engineOperation);
        thread tController(controllerOperation);
        inputManager();
        tPool.join();
        tEngine.join();
    }
    else
    {
        cout << "Usage: poolmanager <water volume>\n";
    }
    return 0;
}

void updatePool() {
    //p = new pool(60.0);
    p->update();
}

void showStats()
{
    float ppm = c->getPPMReading();
    float ph = c->getPHReading();
    cout << "PPM: " << ppm << "\n" << "PH: " << ph << "\n";
}

void reader() {
    for (int i = 1; i > 0; i++) {
        this_thread::sleep_for(chrono::seconds(12));
        float ppm = p->getPPM();
        float ph = p->getPH();
        cout << ppm << endl;
        cout << ph << "\n";
    }
}

void engineOperation()
{
    e->start();
    e->clean();
}

void controllerOperation()
{
    c->manage();
}

void inputManager()
{
    short option;
    cout << "1: Show pool stats\n2: Let a new person swim\n3: Set temp\n4: exit\n";
    for (int i = 1; i > 0; i++) {
        cout << "> ";
        cin >> option;
        //cout << option << endl;
        switch (option) {
        case (1):
            showStats();
            break;
        case (2):
            swim();
            break;
        case (3):
            setTemp();
            break;
        case (4):
            exit(0);
            break;
        default:
            cout << "Unvalid option\n";
            break;
        }
    }
}

void swim()
{
    p->lowerPH();
}

void setTemp()
{
    bool isHighTemp = p->getHiTemp();
    char ch;
    if (isHighTemp){
        cout << "Temperature is currently high, do you wish to set it on normal? (y or n)\n";
        cout << "> ";
        cin >> ch;
        if (ch == 'y'){
            p->setHiTemp(false);
        }
        else if (ch == 'n')
        {
            return;
        }
        else
        {
            cout << "Unvalid option\n";
        }
    }
    else{
         cout << "Temperature is currently low, do you wish to set it on high? (y or n)\n";
        cout << "> ";
        cin >> ch;
        if (ch == 'y'){
            p->setHiTemp(true);
        }
        else if (ch == 'n')
        {
            return;
        }
        else
        {
            cout << "Unvalid option\n";
        }
    }
}