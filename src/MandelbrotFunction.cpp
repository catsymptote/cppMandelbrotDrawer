#include "MandelbrotFunction.h"


//void mandelbrot();
//double planePixelConverter(int pixel, int windowSize, double planeStart, double planeWidth);
//int zIterator(cplx c);
//cplx zFunction(cplx z, cplx c);
//void vectorIntPrinter(std::vector<std::vector<int>> vect);
//std::vector<std::vector<int>> getIterPlane();


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
    //std::cout << "pix:\t\t" << xPix << " : " << yPix << std::endl;
    //std::cout << "scopeMin:\t" << scopeMinX<< " : " << scopeMinY << std::endl;
    //std::cout << "scope:\t" << scopeX<< " : " << scopeY << std::endl;

    //int cplxScopedPlane[xPix][yPix];
    std::vector<std::vector<int>> tmpIterPlane = iterPlane;
    double cplxPointX;
    double cplxPointY;
    //std::cout << "size1: " << tmpIterPlane.size() << std::endl;
    //std::cout << "size2: " << tmpIterPlane.at(0).size() << std::endl;

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
            //std::cout << "x:y" << x << ":" << y << ",\tc:\t" << c.Re << "+i" << c.Im << std::endl;
            //std::cout << "Test 1" << std::endl;
            //std::cout << "y: " << y << ", x: " << x << std::endl;
            tmpIterPlane.at(y).at(x) = MandelbrotFunction::zIterator(c);
        }
    }
    //MandelbrotFunction::vectorIntPrinter(tmpIterPlane);
    iterPlane = tmpIterPlane;
}


/// Converts from pixel/window location to point in the windowed part of the complex plane.
double MandelbrotFunction::planePixelConverter(int pixel, int windowSize, double planeStart, double planeWidth)
{
    //std::cout << "pixel:\t" << pixel << std::endl;// << ",\twindowSize:\t" << windowSize << std::endl;
    //std::cout << "planeStart:\t" << planeStart << ",\tplaneWidth:\t" << planeWidth << std::endl;

    double windowLocation = (double)pixel / (double)(windowSize -1);            // 6/(10-1) = 2/3
    double point = (double)planeStart + windowLocation * (double)planeWidth;    // -2 + (2/3)*4 = 8/3 -2 = (8-6)/3 = 2/3
    //std::cout << "point: " << point << std::endl;
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
    //return cplxAdd (cplxSquare(z), c);
    return cplxSquare(cplxAdd(cplxSquare(z), c));
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
