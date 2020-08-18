#!/bin/bash
g++ PoolManagerSim.cpp pool.cpp controller.cpp engine.cpp sensor.cpp phSensor.cpp ppmSensor.cpp -O4 -pthread --std=c++17
exit 0