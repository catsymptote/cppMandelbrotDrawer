#ifndef COMPLEX_MATHS_H
#define COMPLEX_MATHS_H


#include <cmath>


struct cplx {
    // a + ib / Re + i*Im
    double Re;
    double Im;
};


cplx    cplxAdd(cplx c_1, cplx c_2);
cplx    cplxSquare(cplx c_1);
double  cplxRadius(cplx c_1);


#endif // COMPLEX_MATHS_H
