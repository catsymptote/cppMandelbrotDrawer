#include "ImageConstructor.h"
#include "Tester.h"

#include <iostream>

void run()
{
    ImageConstructor constructor;
    //constructor.setMode(true);
    constructor.run();
}

void test()
{
    Tester test1;
    int runs = 100000000;
    float delta_time = (float)test1.speedTestMaths(runs);

    std::cout << "ms for x runs:\t" << delta_time/1000 << std::endl;
    std::cout << "runs per ms:\t" << runs/delta_time << std::endl;
}

int main()
{
    test();
    return 0;
}
