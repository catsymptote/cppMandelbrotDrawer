#include "mathFunction.h"


mathFunction::mathFunction(int iterations, int xPix, int yPix,
        double scopeMinX, double scopeMinY, double scopeX, double scopeY)
{
    this->iterations    = iterations;
    this->xPix          = xPix;
    this->yPix          = yPix;
    this->scopeMinX     = scopeMinX;
    this->scopeMinY     = scopeMinY;
    this->scopeX        = scopeX;
    this->scopeY        = scopeY;

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


mathFunction::~mathFunction()
{
    //dtor
}


int iterations;
int xPix, yPix;
double scopeMinX, scopeMinY, scopeX, scopeY;

std::vector<std::vector<int> > iterPlane;

std::vector<std::vector<int> > mathFunction::getIterPlane()
{
    return iterPlane;
}


void mathFunction::planeIterator()
{
    std::vector<std::vector<int> > tmpIterPlane = iterPlane;
    double cplxPointX;
    double cplxPointY;

    /// Loop through pixel matrix.
    for(int y = 0; y < yPix; y++)
    {
        for(int x = 0; x < xPix; x++)
        {
            /// Points to test in the complex plane.
            cplxPointX = planePixelConverter(x, xPix, scopeMinX, scopeX);
            cplxPointY = planePixelConverter(y, yPix, scopeMinY, scopeY);

            /// Initial points z and c.
            cplx c;
            c.Re = cplxPointX;
            c.Im = cplxPointY;

            /// Update pixel.
            tmpIterPlane.at(y).at(x) = mathFunction::mandelbrot(c);
        }
    }
    iterPlane = tmpIterPlane;
}


/// Converts from pixel/window location to point in the windowed part of the complex plane.
double mathFunction::planePixelConverter(int pixel, int windowSize, double planeStart, double planeWidth)
{
    double windowLocation = (double)pixel / (double)(windowSize -1);
    double point = (double)planeStart + windowLocation * (double)planeWidth;
    return point;
}


int mathFunction::mandelbrot(cplx c)
{
    cplx z = c;
    for(int i = 0; i < iterations; i++)
    {
        if(z.radius() > 2)
        {
            return i;
        }
        z = mathFunction::zFunction(z, c);
    }
    return -1;
}


cplx mathFunction::zFunction(cplx z, cplx c)
{
    return z.multiplication(z).addition(c);
}



void mathFunction::debugVectorIntPrinter(std::vector<std::vector<int> > vect)
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
