#ifndef COMPLEX_MATHS_H
#define COMPLEX_MATHS_H

#include <cmath>

class cplx
{
public:
    // Constructors and destructor
    cplx();
    cplx(double Re, double Im);
    ~cplx();

    // Get and set methods
    double  getRe();
    double  getIm();
    void    setRe(double Re);
    void    setIm(double Im);

    // Operator overloading
    cplx    operator + (cplx p);
    cplx    operator - (cplx p);
    cplx    operator * (cplx p);
    cplx    operator / (cplx p);
    cplx    operator ^ (int exp);
    double  operator ! ();

    // Real and imaginary variables
    double  Re;
    double  Im;

private:
    // Mathematical methods
    cplx    addition(cplx p);
    cplx    subtraction(cplx p);
    cplx    multiplication(cplx p);
    cplx    division(cplx p);
    double  radius();
};

#endif // COMPLEX_MATHS_H
