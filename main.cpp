#include "complex_maths.h"
#include "MandelbrotFunction.h"

#include <iostream>


int main()
{
    std::cout << "Hello world!" << std::endl;
    MandelbrotFunction run(20, 400, 400, -2.0, -2.0, 4, 4);
    run.mandelbrot();
    return 0;
}
