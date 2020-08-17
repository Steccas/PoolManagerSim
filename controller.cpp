#include <iostream>
#include <chrono>
#include <stdlib.h>
#include <cstdlib>
#include <unistd.h>

#include "controller.hpp"

using namespace std;

controller::controller(phSensor* phS, ppmSensor* ppmS, engine* eng)
{
	this->phS = phS;
	this->ppmS = ppmS;
	this->eng = eng;
}

void controller::read()
{

}

void controller::startEngine()
{

}

void controller::stopEngine()
{

}
