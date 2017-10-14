#include "complex_maths.h"
#include "MandelbrotFunction.h"
#include "imageHandler.h"

#include <iostream>
#include <vector>


int main()
{
    std::cout << "Running..." << std::endl;
    int width   = 3840;
    int height  = 3840;
    MandelbrotFunction zFunc(160, width, height, -2.0, -2.0, 4, 4);
    zFunc.mandelbrot();
    std::cout << "z function complete" << std::endl;
    std::vector<std::vector<int>> iterPlane = zFunc.getIterPlane();
    //std::vector<std::vector<int>> iterPlane;

    imageHandler imag(iterPlane, "img/img.ppm", "P3", width, height, 255);
    std::cout << "File creation initialized" << std::endl;
    //imageHandler imag();
    imag.makeImgFile();
    //std::cout << imag.makeImgFile() << std::endl;

    std::cout << "Finished!" << std::endl;
    return 0;
}
