#include "MandelbrotFunction.h"

#include <iostream>


void mandelbrot();
double planePixelConverter(int pixel, int windowSize, double planeStart, double planeWidth);
int zIterator(cplx z, cplx c);
cplx zFunction(cplx z, cplx c);


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

    for(int y = 0; y < scopeY; y++)
    {
        std::vector<int> tmpRow;
        for(int x = 0; x < scopeX; x++)
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


void MandelbrotFunction::mandelbrot()
{
    //int cplxScopedPlane[xPix][yPix];
    std::vector<std::vector<int>> tmpIterPlane;
    double cplxPointX;
    double cplxPointY;

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
            cplx z = c;
            tmpIterPlane[x][y] = zIterator(z, c);
        }
    }
    iterPlane = tmpIterPlane;
}


/// Converts from pixel/window location to point in the windowed part of the complex plane.
double MandelbrotFunction::planePixelConverter(int pixel, int windowSize, double planeStart, double planeWidth)
{
    double windowLocation = pixel / (windowSize -1);
    double point = planeStart + windowLocation * planeWidth;
    return point;
}


int zIterator(cplx z, cplx c)
{
    std::cout << "Test" << std::endl;
    for(int i = 0; i < iterations; i++)
    {
        if(cplxRadius(z) > 2)
        {
            return i;
        }
        z = zFunction(z, c);
    }
    return -1;  // Does not pass 2 within iterations
}


cplx zFunction(cplx z, cplx c)
{
    return cplxAdd (cplxSquare(z), c);
}
