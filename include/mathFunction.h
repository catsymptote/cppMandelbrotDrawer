#ifndef MANDELBROTFUNCTION_H
#define MANDELBROTFUNCTION_H


#include "complexMath.h"

#include <iostream>
#include <vector>


class mathFunction
{
    public:
        mathFunction(int iterations, int xPix, int yPix,
            double scopeMinX, double scopeMinY, double scopeX, double scopeY);
        virtual ~mathFunction();

        void planeIterator();
        std::vector<std::vector<int> > getIterPlane();

    protected:

    private:
        int iterations;
        int xPix, yPix;
        double scopeMinX, scopeMinY, scopeX, scopeY;
        std::vector<std::vector<int> > iterPlane;

        double planePixelConverter(int pixel, int windowSize, double planeStart, double planeWidth);
        int mandelbrot(cplx c);
        cplx zFunction(cplx z, cplx c);

        void debugVectorIntPrinter(std::vector<std::vector<int> > vect);
};

#endif // MANDELBROTFUNCTION_H
