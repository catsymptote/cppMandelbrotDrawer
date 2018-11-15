#include "complexMath.h"
#include "mathFunction.h"
#include "imageHandler.h"
#include "colorIterator.h"
#include "cmd.h"

#include <iostream>
#include <vector>


/*
std::string execCmd(const char* cmd)
{
    std::cout << cmd << std::endl;
    std::array<char, 128> buffer;
	std::string result;
	std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
	if (!pipe) throw std::runtime_error("popen() failed!");
	while (!feof(pipe.get())) {
		if (fgets(buffer.data(), 128, pipe.get()) != nullptr)
			result += buffer.data();
	}
	return result;
}


void runCMD(const char* fileName)
{
    std::string fn = fileName;

    //imag.altExecCmd("python ppmToPng.py");
    //imag.altExecCmd("ls");

    std::string delCmd = "del " + fn + ".ppm";
    char *delChr = &delCmd[0];
    //std::cout << execCmd(delChr) << std::endl;

    std::string mvCmd = "mv " + fn + ".png" + " img/" + fn + ".png";
    char *mvChr = &mvCmd[0];
    std::cout << execCmd(mvChr) << std::endl;

    std::string startCmd = "start img/" + fn + ".png";
    char *startChr = &startCmd[0];
    //std::cout << execCmd(startChr) << std::endl;
}
*/


int main()
{
    std::cout << "Running..." << std::endl;
    /// Set variables
    int imageWidth          = 3840 + 1;
    int imageHeight         = 3840 + 1;

    double fieldMinX        = -2.1;
    double fieldMinY        = -2.1;
    double fieldSizeX       = 4.2;
    double fieldSizeY       = 4.2;

    std::string fnStart     = "img";
    std::string fExt        = ".ppm";
    std::string tmpDir      = "imgTmp\\";

    int maxIterations       = 100;
    int outputImages        = 1;
    int deltaIterStep       = 1;
    int totalSteps          = outputImages + maxIterations;


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
    std::cout << cmd::execCmd("python ppmToPng.py") << std::endl;

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
    return 0;
}
