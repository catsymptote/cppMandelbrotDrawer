#ifndef MANDELBROTFUNCTION_H
#define MANDELBROTFUNCTION_H


#include "complexMath.h"

#include <iostream>
#include <vector>


class mathFunction
{
    public:
        mathFunction();
        mathFunction(int iterations, int xPix, int yPix,
            double scopeMinX, double scopeMinY, double scopeX, double scopeY);
        virtual ~mathFunction();

        void altPlaneIterator();
        void planeIterator();
        std::vector<std::vector<int> > getIterPlane();
        cplx zFunction(cplx z, cplx c); // public for testing purposes #theProperWay

    protected:

    private:
        int iterations;
        int xPix, yPix;
        double scopeMinX, scopeMinY, scopeX, scopeY;
        std::vector<std::vector<int> > iterPlane;

        double planePixelConverter(int pixel, int windowSize, double planeStart, double planeWidth);
        bool inPlane(cplx z);
        int pointToPixel(double point, int maxPix, double scopeMin, double scope);
        int mandelbrot(cplx c);


        void debugVectorIntPrinter(std::vector<std::vector<int> > vect);
};

#endif // MANDELBROTFUNCTION_H
