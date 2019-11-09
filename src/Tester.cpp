#include "Tester.h"


Tester::Tester()
{
    //ctor
}

Tester::~Tester()
{
    //dtor
}


unsigned __int64 Tester::getTime()
{
    unsigned __int64 current_time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    return current_time;
}


unsigned __int64 Tester::speedTestMaths(unsigned int runs_int)
{
    /// Return ms it takes to run zFunction x amount of times.
    unsigned int runs = runs_int;
    mathFunction test_math;

    cplx z(1, 2);
    cplx c(3, 4);
    cplx a;

    unsigned __int64 start_time = this->getTime();
    for(unsigned int i = 0; i < runs; i++)
    {
        a = test_math.zFunction(z, c);
    }
    unsigned __int64 end_time = this->getTime();

    unsigned int delta_time = end_time - start_time;
    return delta_time;
}
