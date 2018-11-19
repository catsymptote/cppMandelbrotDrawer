#ifndef COMPLEX_MATHS_H
#define COMPLEX_MATHS_H


#include <cmath>


class cplx
{
public:
    cplx();
    cplx(double Re, double Im);
    ~cplx();

    double  getRe();
    double  getIm();
    void    setRe(double Re);
    void    setIm(double Im);

    double  Re;
    double  Im;

//private:
    cplx    addition(cplx p);
    cplx    subtraction(cplx p);
    cplx    multiplication(cplx p);
    cplx    division(cplx p);
    double  radius();

};

/*
struct cplx {
    // a + ib / Re + i*Im
    double Re;
    double Im;
};


cplx    cplxAdd(cplx c_1, cplx c_2);
cplx    cplxSquare(cplx c_1);
double  cplxRadius(cplx c_1);
*/

#endif // COMPLEX_MATHS_H
