#include "complexMath.h"
#include "mathFunction.h"
#include "imageHandler.h"
#include "colorIterator.h"

#include <iostream>
#include <vector>


int main()
{
    std::cout << "Running..." << std::endl;
    /// Set variables
    int imageWidth      = 1024 + 1;
    int imageHeight     = 1024 + 1;
    int maxIterations   = 128;
    double fieldMinX    = -2.1;
    double fieldMinY    = -2.1;
    double fieldSizeX   = 4.2;
    double fieldSizeY   = 4.2;

    /// Construct the Z-function and run its plane iterator.
    //mathFunction zFunc(100000, imageWidth, imageHeight, -0.750045367143 -0.000000001, 0.004786271734 -0.000000001, 0.000000002, 0.000000002);    // avg 72k iters per pixel :|   http://colinlmiller.com/fractals/gallery.htm
    mathFunction zFunc(maxIterations, imageWidth, imageHeight, fieldMinX, fieldMinY, fieldSizeX, fieldSizeY);
    zFunc.planeIterator();
    std::cout << "z function complete" << std::endl;
    std::vector<std::vector<int> > iterPlane = zFunc.getIterPlane();

    /// Construct and make the PPM image of the field.
    imageHandler imag(iterPlane, "img.ppm", "P3", imageWidth, imageHeight, 255);
    std::cout << "File creation initialized" << std::endl;
    imag.makeImgFile();

    /// Compile image to png and place in img/ folder.
    //imag.altExecCmd("python img/ppmToPng.py");
    //imag.altExecCmd("ls");
    std::cout << imag.execCmd("python img/ppmToPng.py") << std::endl;
    std::cout << imag.execCmd("del img.ppm") << std::endl;
    std::cout << imag.execCmd("mv img.png img/img.png") << std::endl;

    std::cout << "Finished!" << std::endl;
    return 0;
}
