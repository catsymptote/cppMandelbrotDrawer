#include "complexMath.h"


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
