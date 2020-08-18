#include <iostream>
#include <chrono>
#include <stdlib.h>
#include <cstdlib>
#include <unistd.h>

#include "pool.hpp"
#include "engine.hpp"

using namespace std;

engine::engine(pool* p, int _p)
{
	_pool = p;
	power = _p;
	isOn = false;
}

void engine::clean()
{
	for (int i = 1; i > 0; i++) {
		this_thread::sleep_for(chrono::seconds(power));
		if(isOn) _pool->risePH();
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
