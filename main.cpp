#include "complexMath.h"
#include "mathFunction.h"
#include "imageHandler.h"
#include "colorIterator.h"

#include <iostream>
#include <vector>


int main()
{
    std::cout << "Running..." << std::endl;
    int width   = 1000;
    int height  = 1000;
    //mathFunction zFunc(100000, width, height, -0.750045367143 -0.000000001, 0.004786271734 -0.000000001, 0.000000002, 0.000000002);    // avg 72k iters per pixel :|   http://colinlmiller.com/fractals/gallery.htm
    mathFunction zFunc(150, width, height, -2, -2, 4, 4);
    zFunc.planeIterator();
    std::cout << "z function complete" << std::endl;
    std::vector<std::vector<int> > iterPlane = zFunc.getIterPlane();

    imageHandler imag(iterPlane, "img/img.ppm", "P3", width, height, 255);
    std::cout << "File creation initialized" << std::endl;

    imag.makeImgFile();

    std::cout << "Finished!" << std::endl;
    return 0;
}
