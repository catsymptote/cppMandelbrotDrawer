#include "ImageConstructor.h"

#include "complexMath.h"
#include "mathFunction.h"
#include "imageHandler.h"
#include "colorIterator.h"
#include "cmd.h"

#include <iostream>
#include <vector>


ImageConstructor::ImageConstructor()
{
    //ctor
}

ImageConstructor::~ImageConstructor()
{
    //dtor
}


void ImageConstructor::setMode(bool buddah)
{
    this->buddah = buddah;
}


void ImageConstructor::run()
{
    std::cout << "Running..." << std::endl;
    /// Set variables
    int imageWidth          = 1024 + 1;
    int imageHeight         = 1024 + 1;

    double fieldMinX        = -2.0;
    double fieldMinY        = -2.0;
    double fieldSizeX       = 4.0;
    double fieldSizeY       = 4.0;

    std::string fnStart     = "img";
    std::string fExt        = ".ppm";
    std::string tmpDir      = "imgTmp\\";

    int maxIterations       = 128;
    int outputImages        = 1;
    int deltaIterStep       = 1;
    //int totalSteps          = outputImages + maxIterations;


    for (int i = 0; i < outputImages; i++)
    {
        /// Generate file name
        std::string cmdStr = fnStart;
        if (outputImages > 1)
            cmdStr += std::to_string(i);
        char *fname = &cmdStr[0];

        /// Construct the Z-function and run its plane iterator.
        //mathFunction zFunc(100000, imageWidth, imageHeight, -0.750045367143 -0.000000001, 0.004786271734 -0.000000001, 0.000000002, 0.000000002);    // avg 72k iters per pixel :|   http://colinlmiller.com/fractals/gallery.htm
        mathFunction zFunc(maxIterations, imageWidth, imageHeight, fieldMinX, fieldMinY, fieldSizeX, fieldSizeY);
        maxIterations += deltaIterStep;
        if(this->buddah)
            zFunc.altPlaneIterator();
        else
            zFunc.planeIterator();

        std::cout << "z function complete" << std::endl;
        std::vector<std::vector<int> > iterPlane = zFunc.getIterPlane();

        /// Construct and make the PPM image of the field.
        imageHandler imag(iterPlane, tmpDir + fname + fExt, "P3", imageWidth, imageHeight, 255);
        std::cout << "File creation initialized" << std::endl;
        imag.makeImgFile();
    }

    /// Compile images to png
    std::cout << "\nPython:" << std::endl;
    std::cout << cmd::execCmd("pipenv run ppmToPng.py") << std::endl;

    for (int i = 0; i < outputImages; i++)
    {
        /// Generate file name
        std::string cmdStr = fnStart;
        if (outputImages > 1)
            cmdStr += std::to_string(i);
        char *fname = &cmdStr[0];

        std::cout << "\nCommands:" << std::endl;
        cmd::del(fname);
        cmd::mov(fname);
        if(outputImages < 2)
            cmd::open(fname);

        std::cout << "\nProgram finished!" << std::endl;
    }
}
