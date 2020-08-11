#ifndef pool_h
#define pool_h

using namespace std;

class pool
{
private:
    water *w;
    float water;
    float ph;
    float ppm;
public:
    pool();
    void update();
    float getPH();
    float getPPM();
};

#endif