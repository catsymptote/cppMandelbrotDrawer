#include "complexMath.h"

//////////////////
// Constructors //
//////////////////

cplx::cplx()
{
    this->Re = 0;
    this->Im = 0;
}

cplx::cplx(double Re, double Im)
{
    this->Re = Re;
    this->Im = Im;
}

cplx::~cplx() {}


///////////////////////
// Get/set functions //
///////////////////////

double cplx::getRe() { return this->Re; }
double cplx::getIm() { return this->Im; }
void cplx::setRe(double Re) { this->Re = Re; }
void cplx::setIm(double Im) { this->Im = Im; }


////////////////////
// Math functions //
////////////////////

cplx cplx::addition(cplx p)
{
    double Real = this->Re + p.getRe();
    double Imag = this->Im + p.getIm();
    return cplx(Real, Imag);
}

cplx cplx::subtraction(cplx p)
{
    double Real = this->Re - p.getRe();
    double Imag = this->Im - p.getIm();
    return cplx(Real, Imag);
}

cplx cplx::multiplication(cplx p)
{
    double Real = this->Re * p.getRe() - this->Im * p.getIm();
    double Imag = this->Re * p.getIm() + this->Im * p.getRe();
    return cplx(Real, Imag);
}

cplx cplx::division(cplx p)
{
    double Real = this->Re * p.getRe() + this->Im * p.getIm();
    double Imag = p.getRe() * this->Im - this->Re * p.getIm();
    double divisor = pow(this->Re, 2) + this->Im * p.getIm();
    return cplx(Real/divisor, Imag/divisor);
}

double cplx::radius()
{
    return sqrt(pow(this->Re, 2) + pow(this->Im, 2));
}


/*
cplx cplxAdd(cplx c_1, cplx c_2)
{
    cplx sum;
    sum.Re = c_1.Re + c_2.Re;
    sum.Im = c_1.Im + c_2.Im;
    return sum;
}


cplx cplxSquare(cplx c_1)
{
    cplx power;
    power.Re = pow(c_1.Re, 2) - pow(c_1.Im, 2);
    power.Im = 2 * c_1.Re * c_1.Im;
    return power;
}


double cplxRadius(cplx c_1)
{
    double radius = sqrt(pow(c_1.Re, 2) + pow(c_1.Im, 2));
    return radius;
}
*/
