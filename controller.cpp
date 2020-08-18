#include <iostream>
#include <chrono>
#include <stdlib.h>
#include <cstdlib>
#include <unistd.h>

#include "controller.hpp"

using namespace std;

controller::controller(phSensor* phS, ppmSensor* ppmS, engine* eng, int time)
{
	this->phS = phS;
	this->ppmS = ppmS;
	this->eng = eng;
	this->time = time;
}

void controller::read()
{
	ppm = ppmS->read();
	ph = phS->read();
}

void controller::manage()
{
	for (int i = 1; i > 0; i++) {
		this_thread::sleep_for(chrono::seconds(time));
		this->read();
		if (ppm < 1.2) { 
			cout << "Chlorine too low (" << ppm << "), injecting more." << "\n> ";
			ppmS->injectChlorine(); 
		}
		if (ph < 7.3) {
			cout << "PH is getting low (" << ph << "), starting engine.\n> ";
			startEngine();
		}
		if (ph > 7.8) {
			cout << "PH is getting high (" << ph << "), stopping engine." << "\n> ";
			stopEngine();
		}
	}
}

float controller::getPHReading()
{
	return ph;
}

float controller::getPPMReading()
{
	return ppm;
}

void controller::startEngine()
{
	eng->start();
}

void controller::stopEngine()
{
	eng->stop();
}
