#include "imageHandler.h"


/// PPM / PGM / PBM guide: http://utk.claranguyen.me/guide/PPM.html
/// For simple PPM -> PNG conversion: https://convertio.co/ppm-png/

std::vector<int> vect2ToVect(std::vector<std::vector<int>> plane);


imageHandler::imageHandler(std::vector<std::vector<int>> &iterPlane, std::string filePath, std::string magicNumber, int width, int height, int colorRange)
//imageHandler::imageHandler()
{
    //someArray[];
    this->filePath      = filePath;
    this->magicNumber   = magicNumber;
    this->width         = width;
    this->height        = height;
    this->colorRange    = colorRange;
    //this->m_iterPlane   = iterPlane;
    this->ppmVector     = vect2ToVect(iterPlane);
}

imageHandler::~imageHandler()
{
    //dtor
}

/// File vaiables
std::string filePath    = "testImg.ppm";
//std::string filePath;
//std::string fileName;

/// Image format variables
std::string magicNumber;// = "P3";
int         width;//       = 3;
int         height;//      = 2;
int         colorRange;//  = 255;

std::vector<std::vector<int>> m_iterPlane;
std::vector<int> ppmVector;

int testPic[3*2*3] = {
    255, 0, 0,      0, 255, 0,      0,  0, 255,
    255, 255, 0,    255, 255,       255, 0, 0 ,0
};



std::vector<int> imageHandler::vect2ToVect(std::vector<std::vector<int>> plane)
{
    int k = 2; // Color constant
    int color;
    std::vector<int> vect;
    for(int y = 0; y < plane.size(); y++)
    {
        for(int x = 0; x < plane.at(y).size(); x++)
        {


            //vect.push_back(plane.at(y).at(x));
            // Color fixer

            color = k*plane.at(y).at(x);
            if(color > 255)
            {
                color = 255;
            }

            if(plane.at(y).at(x) != -1)
            {
                vect.push_back(color);
                vect.push_back(color);
                vect.push_back(255);
            }
            else if(plane.at(y).at(x) == -1)
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
    //bool success = true;

    std::ofstream imgFile(filePath);
    imgFile << magicNumber << "\n" << width << " " << height << "\n" << colorRange << "\n";

    //for(int y = 0; y < 1; y++)
    //{
    int pixPerLine = 10;
    int pixSize = 3;    // RGB == 3, RGBA == 4, etc
    int counter = 0;

    for(int x = 0; x < ppmVector.size(); x++)
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

    /*
    /// Old version
    for(int x = 0; x < ppmVector.size(); x++)
    {
        imgFile << ppmVector.at(x) << "\t";

        if(x%pixSize == pixSize -1)
        {
            if(counter%pixPerLine == pixPerLine -1)
            {
                imgFile << "\n";
            counter = 0;
            }
            else
            {
                imgFile << "\t\t";
                counter++;
            }

        }

    }
    */
    //}

    //return success;
}
