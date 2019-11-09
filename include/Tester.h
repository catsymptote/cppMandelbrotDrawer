#ifndef TESTER_H
#define TESTER_H

#include "mathFunction.h"
#include "complexMath.h"
#include <chrono>


class Tester
{
    public:
        Tester();
        virtual ~Tester();

        unsigned __int64 speedTestMaths(unsigned int runs_int);

    protected:

    private:
        unsigned __int64 getTime();
};

#endif // TESTER_H
