#ifndef sensor_h
#define sensor_h

using namespace std;

class sensor
{
private:
    pool *p;
public:
    sensor();
    float read();
};

#endif