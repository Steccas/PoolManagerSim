#include <iostream>
#include <chrono>
#include <stdlib.h>
#include <cstdlib>
#include <unistd.h>

#include "pool.hpp"
#include "engine.hpp"

using namespace std;

engine::engine(pool* p, float p)
{
	pool = p;
	timer = t;
	isOn = false;
}

void engine::clean()
{
	for (int i = 1; i > 0; i++) {
		this_thread::sleep_for(chrono::seconds(t));
		if(isOn) p->lowerPH();
	}
}

void engine::start()
{
	isOn = true;
}

void engine::stop()
{
	isOn = false;
}
