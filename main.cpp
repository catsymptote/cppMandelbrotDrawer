#include "complex_maths.h"
#include "MandelbrotFunction.h"
#include "imageHandler.h"

#include <iostream>


int main()
{
    std::cout << "Hello world!" << std::endl;
    MandelbrotFunction zFunc(20, 5, 5, -2.0, -2.0, 4, 4);
    zFunc.mandelbrot();
    std::vector<std::vector<int>> iterPlane = zFunc.getIterPlane();
    //std::vector<std::vector<int>> iterPlane;

    imageHandler imag(iterPlane, "testImage.ppm", "P3", 512, 512, 255);
    //imageHandler imag();

    //std::cout << imag.makeImgFile() << std::endl;

    return 0;
}
