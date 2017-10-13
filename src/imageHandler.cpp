#include "imageHandler.h"


/// PPM / PGM / PBM guide: http://utk.claranguyen.me/guide/PPM.html


imageHandler::imageHandler(std::vector<std::vector<int>> &iterPlane, std::string filePath, std::string magicNumber, int width, int height, int colorRange)
//imageHandler::imageHandler()
{
    ///*
    //someArray;
    this->filePath      = filePath;
    this->magicNumber   = magicNumber;
    this->width         = width;
    this->height        = height;
    this->colorRange    = colorRange;
    this->iterPlane     = iterPlane;
    //*/
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
std::string magicNumber = "P3";
int         width       = 3;
int         height      = 2;
int         colorRange  = 255;

std::vector<std::vector<int>> iterPlane;

int testPic[3*2*3] = {
    255, 0, 0,      0, 255, 0,      0,  0, 255,
    255, 255, 0,    255, 255,       255, 0, 0 ,0
};



void imageHandler::makeImgFile()
{
    //bool success = true;

    std::ofstream imgFile(filePath);
    imgFile << magicNumber << "\n" << width << "\n" << height << "\n" << colorRange << "\n";

    for(int y = 0; y < 1; y++)
    {
        for(int x = 0; x < 9*2; x++)
        {
            imgFile << testPic[x] << "\t";
            if(x%3 == 2 && x != 9-1 && x != 0 && true)
            {
                imgFile << "\t";
            }
            else if(x == 9-1)
            {
                imgFile << "\n";
            }
        }
    }

    //return success;
}
