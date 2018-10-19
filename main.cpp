#include "complexMath.h"
#include "mathFunction.h"
#include "imageHandler.h"
#include "colorIterator.h"

#include <iostream>
#include <vector>


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


int main()
{
    std::cout << "Running..." << std::endl;
    /// Set variables
    int imageWidth          = 1024 + 1;
    int imageHeight         = 1024 + 1;
    int maxIterations       = 0;
    double fieldMinX        = -2.1;
    double fieldMinY        = -2.1;
    double fieldSizeX       = 4.2;
    double fieldSizeY       = 4.2;
    std::string fnStart     = "img";
    std::string fExt        = ".ppm";
    std::string tmpDir      = "imgTmp/";
    int step                = 5;
    int totalSteps          = 10 + 1;
    int stepStart           = 0;

    for (int i = stepStart; i < totalSteps; i++)
    {
        /// Generate file name
        std::string cmdStr = fnStart + std::to_string(i);// + fExt;
        char *cmdChr = &cmdStr[0];

        /// Construct the Z-function and run its plane iterator.
        //mathFunction zFunc(100000, imageWidth, imageHeight, -0.750045367143 -0.000000001, 0.004786271734 -0.000000001, 0.000000002, 0.000000002);    // avg 72k iters per pixel :|   http://colinlmiller.com/fractals/gallery.htm
        mathFunction zFunc(maxIterations, imageWidth, imageHeight, fieldMinX, fieldMinY, fieldSizeX, fieldSizeY);
        maxIterations += step;
        zFunc.planeIterator();
        std::cout << "z function complete" << std::endl;
        std::vector<std::vector<int> > iterPlane = zFunc.getIterPlane();

        /// Construct and make the PPM image of the field.
        imageHandler imag(iterPlane, tmpDir + cmdChr + fExt, "P3", imageWidth, imageHeight, 255);
        std::cout << "File creation initialized" << std::endl;
        imag.makeImgFile();
    }

    /// Compile images to png
    std::cout << execCmd("python ppmToPng.py") << std::endl;

    for (int i = stepStart; i < totalSteps; i++)
    {
        /// Generate file name
        std::string cmdStr = fnStart + std::to_string(i);// + fExt;
        char *cmdChr = &cmdStr[0];

         /// Place in img/ folder.
        //runCMD(cmdChr);
        std::string delCmd = "del " + tmpDir + cmdStr + ".ppm";
        char *delChr = &delCmd[0];
        std::cout << execCmd(delChr) << std::endl;

        std::string mvCmd = "mv " + tmpDir + cmdStr + ".png" + " img/" + cmdStr + ".png";
        char *mvChr = &mvCmd[0];
        std::cout << execCmd(mvChr) << std::endl;

        //std::string startCmd = "start img/" + cmdStr + ".png";
        //char *startChr = &startCmd[0];
        //std::cout << execCmd(startChr) << std::endl;

        std::cout << "Finished!" << std::endl;
    }
    return 0;
}
