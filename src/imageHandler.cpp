#include "imageHandler.h"


/// PPM / PGM / PBM guide: http://utk.claranguyen.me/guide/PPM.html
/// For simple PPM -> PNG conversion: https://convertio.co/ppm-png/

std::vector<int> vect2ToVect(std::vector<std::vector<int> > plane);


imageHandler::imageHandler(std::vector<std::vector<int> > &iterPlane, std::string filePath, std::string magicNumber, int width, int height, int colorRange)
{
    this->filePath      = filePath;
    this->magicNumber   = magicNumber;
    this->width         = width;
    this->height        = height;
    this->colorRange    = colorRange;
    this->ppmVector     = vect2ToVect(iterPlane);
}

imageHandler::~imageHandler()
{
    //dtor
}


/// File vaiables
std::string filePath    = "testImg.ppm";

/// Image format variables
std::string magicNumber;
int         width;
int         height;
int         colorRange;
std::vector<std::vector<int> > m_iterPlane;
std::vector<int> ppmVector;

int testPic[3*2*3] = {
    255, 0, 0,      0, 255, 0,      0,  0, 255,
    255, 255, 0,    255, 255,       255, 0, 0 ,0
};



std::vector<int> imageHandler::vect2ToVect(std::vector<std::vector<int> > plane)
{
    int k = 5; // Color constant
    colorIterator cIter(k);

    std::vector<int> vect;
    for(unsigned int y = 0; y < plane.size(); y++)
    {
        for(unsigned int x = 0; x < plane.at(y).size(); x++)
        {
            int pixIter = plane.at(y).at(x);

            if(pixIter != -1)
            {
                std::vector<int> pixelColor = cIter.incrementColor(pixIter);
                //std::vector<int> pixelColor = cIter.incrementColor(1);
                vect.insert(vect.end(), pixelColor.begin(), pixelColor.end());
                cIter.resetColorSpace();
            }
            else if(pixIter == -1)
            {
                vect.push_back(0);
                vect.push_back(0);
                vect.push_back(0);
            }
        }
    }
    return vect;
}


void imageHandler::makeImgFile()
{
    std::ofstream imgFile(filePath);
    imgFile << magicNumber << "\n" << width << " " << height << "\n" << colorRange << "\n";

    //int pixPerLine = 10;
    unsigned int pixSize = 3;    // RGB == 3, RGBA == 4
    //int counter = 0;

    for(unsigned int x = 0; x < ppmVector.size(); x++)
    {
        imgFile << ppmVector.at(x);
        if(x%pixSize != pixSize -1)
        {
            imgFile << "\t";
        }
        else
        {
            imgFile << "\n";
        }
    }
}


std::string imageHandler::execCmd(const char* cmd)
{
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


void imageHandler::altExecCmd(const char* cmd)
{
    //std::cout << cmd << std::endl;
    ShellExecute(GetDesktopWindow(), "open", "cmd.exe", cmd, 0, SW_HIDE);
    //GetDesktopWindow()
}
