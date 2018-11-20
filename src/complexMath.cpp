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


//////////////////////////
// Operator overloading //
//////////////////////////

cplx cplx::operator + (const cplx p)
{
    return this->addition(p);
}

cplx cplx::operator - (const cplx p)
{
    return this->subtraction(p);
}

cplx cplx::operator * (const cplx p)
{
    return this->multiplication(p);
}

cplx cplx::operator / (const cplx p)
{
    return this->division(p);
}

cplx cplx::operator ^ (int exp)
{
    cplx q;
    q.Re = this->Re;
    q.Im = this->Im;

    for(int i = 1; i < exp; i++)
        q = q*q;

    return q;
}

double cplx::operator ! ()
{
    return this->radius();
}
