#include "ppmSensor.hpp"

ppmSensor::ppmSensor(pool* _p) : sensor(_p)
{

}

float ppmSensor::read()
{
	return p->getPPM();
}

void ppmSensor::injectChlorine()
{
	p->risePPM();
}
