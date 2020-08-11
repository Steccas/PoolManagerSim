#ifndef controller_h
#define controller_h

using namespace std;

class controller
{
private:
    float ph;
    //pool *p;
    phSensor *phSens;
    ppmSensor *ppmSens;
    engine *eng;
public:
    controller();
    void read();
    void startEngine();
    void stopEngine();
};

#endif