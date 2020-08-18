#include "phSensor.hpp"

phSensor::phSensor(pool* _p) : sensor(_p)
{

}

float phSensor::read()
{
	return p->getPH();
}
