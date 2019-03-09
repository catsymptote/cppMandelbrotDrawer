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




/// Math iteration counter function.
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



/// Math iteration counter function.
void mathFunction::altPlaneIterator()
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
            cplx z = c;

            int counter = 0;
            /// Find number path.
            //while( !z < 2 )//abs(z.Re) < 2.0 && abs(z.Im) < 2.0 ) // 2 should be changed to scopeMinX...
            while( inPlane(z) )
            {
                if(counter > 512)
                    break;
                counter++;

                int z_x = pointToPixel(z.Re, xPix, scopeMinX, scopeX);
                int z_y = pointToPixel(z.Im, yPix, scopeMinY, scopeY);
                tmpIterPlane.at(z_y).at(z_x) ++;
                z = mathFunction::zFunction(z, c);
            }
        }
        //printf("%i\n", y);
    }
    iterPlane = tmpIterPlane;
}


bool mathFunction::inPlane(cplx z)
{
    bool in = true;

    if(z.Re <= -2)//scopeMinX)
        in = false;
    if(z.Re >= 2)//scopeMinX + scopeX)
        in = false;
    if(z.Im <= -2)//scopeMinY)
        in = false;
    if(z.Im >= 2)//scopeMinY + scopeY)
        in = false;

    return in;
}


// Convert one part of a point to a pixel value.
int mathFunction::pointToPixel(double point, int maxPix, double scopeMin, double scope)
{
    return (int)(point * maxPix/scope - maxPix/scopeMin);
}



/// Standard Maldelbrot iteration function.
int mathFunction::mandelbrot(cplx c)
{
    cplx z = c;
    for(int i = 0; i < iterations; i++)
    {
        if(!z > 2)
        {
            return i;
        }
        z = mathFunction::zFunction(z, c);
    }
    return -1;
}


cplx mathFunction::zFunction(cplx z, cplx c)
{
    return (z^2) + c;
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
