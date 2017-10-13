#include "MandelbrotFunction.h"

#include <iostream>


void mandelbrot();
double planePixelConverter(int pixel, int windowSize, double planeStart, double planeWidth);
int zIterator(cplx c);
cplx zFunction(cplx z, cplx c);
void vectorIntPrinter(std::vector<std::vector<int>> vect);
std::vector<std::vector<int>> getIterPlane();


MandelbrotFunction::MandelbrotFunction(int iterations, int xPix, int yPix,
        double scopeMinX, double scopeMinY, double scopeX, double scopeY)
{
    this->iterations    = iterations;
    this->xPix          = xPix;
    this->yPix          = yPix;
    this->scopeMinX     = scopeMinX;
    this->scopeMinY     = scopeMinY;
    this->scopeX        = scopeX;
    this->scopeY        = scopeY;

    //int planeMatrix[scopeX][scopeY];

    for(int y = 0; y < yPix; y++)
    {
        std::vector<int> tmpRow;
        for(int x = 0; x < xPix; x++)
        {
            tmpRow.push_back(0);
        }
        iterPlane.push_back(tmpRow);
    }

}


MandelbrotFunction::~MandelbrotFunction()
{
    //dtor
}


int iterations;
int xPix, yPix;
double scopeMinX, scopeMinY, scopeX, scopeY;

//private int windowSize[2]    = {1024, 512};
//private double planeScope[4] = {-2, -2, 4, 4};    // xMin, yMin, xSize, ySize

//private int planeMatrix[scopeX][scopeY];

std::vector<std::vector<int>> iterPlane;


std::vector<std::vector<int>> MandelbrotFunction::getIterPlane()
{
    return iterPlane;
}


void MandelbrotFunction::mandelbrot()
{
    //int cplxScopedPlane[xPix][yPix];
    std::vector<std::vector<int>> tmpIterPlane = iterPlane;
    double cplxPointX;
    double cplxPointY;
    std::cout << "size1: " << tmpIterPlane.size() << std::endl;
    std::cout << "size2: " << tmpIterPlane.at(0).size() << std::endl;

    /// Loop through pixel matrix
    for(int y = 0; y < yPix; y++)
    {
        for(int x = 0; x < xPix; x++)
        {
            /// Points to test in the complex plane
            cplxPointX = planePixelConverter(x, xPix, scopeMinX, scopeX);
            cplxPointY = planePixelConverter(y, yPix, scopeMinY, scopeY);

            /// Initial points z and c
            cplx c;
            c.Re = cplxPointX;
            c.Im = cplxPointY;
            //std::cout << "Test 1" << std::endl;
            std::cout << "y: " << y << ", x: " << x << std::endl;
            tmpIterPlane.at(y).at(x) = MandelbrotFunction::zIterator(c);
        }
    }
    MandelbrotFunction::vectorIntPrinter(tmpIterPlane);
    iterPlane = tmpIterPlane;
}


/// Converts from pixel/window location to point in the windowed part of the complex plane.
double MandelbrotFunction::planePixelConverter(int pixel, int windowSize, double planeStart, double planeWidth)
{
    double windowLocation = pixel / (windowSize -1);
    double point = planeStart + windowLocation * planeWidth;
    return point;
}


int MandelbrotFunction::zIterator(cplx c)
{
    cplx z = c;
    //std::cout << "Test 2" << std::endl;
    for(int i = 0; i < iterations; i++)
    {
        if(cplxRadius(z) > 2)
        {
            return i;
        }
        z = MandelbrotFunction::zFunction(z, c);
    }
    return -1;  // Does not pass 2 within iterations
}


cplx MandelbrotFunction::zFunction(cplx z, cplx c)
{
    return cplxAdd (cplxSquare(z), c);
}



void MandelbrotFunction::vectorIntPrinter(std::vector<std::vector<int>> vect)
{
    std::cout << "\nVector:\n";
    for(int y = 0; y < vect.size(); y++)
    {
        for(int x = 0; x < vect[y].size(); x++)
        {
            std::cout << vect.at(x).at(y) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
