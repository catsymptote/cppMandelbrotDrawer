#ifndef MANDELBROTFUNCTION_H
#define MANDELBROTFUNCTION_H


#include "complex_maths.h"

#include <vector>

class MandelbrotFunction
{
    public:
        MandelbrotFunction(int iterations, int xPix, int yPix,
            double scopeMinX, double scopeMinY, double scopeX, double scopeY);
        virtual ~MandelbrotFunction();

        void mandelbrot();

    protected:

    private:
        int iterations;
        int xPix, yPix;
        double scopeMinX, scopeMinY, scopeX, scopeY;
        //int planeMatrix[scopeX][scopeY];
        std::vector<std::vector<int>> iterPlane;

        double planePixelConverter(int pixel, int windowSize, double planeStart, double planeWidth);
        cplx zFunction(cplx z, cplx c);
};

#endif // MANDELBROTFUNCTION_H
