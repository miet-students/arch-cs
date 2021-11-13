#include <iostream>
#include <cstdint>
#include <cmath>
//DISTFILES += \  task5.S

extern "C" double fp_var_math(double x, double y);
double fp_var_math(double x, double y)
{
    double f = pow(x+5.3, (double)1/3)+y;
    std::cout<<"From cpp: "<<f<<std::endl;
    return f;
}

extern "C" double cubrt(double x);
double cubrt(double x)
{
    double f = pow(x,(double)1/3);
    std::cout<<"Call cubic root: "<<f<<std::endl;
    return f;
}

extern "C" double add(double x, double y);
double add(double x, double y)
{
    double f = x+y;
    std::cout<<"Call add: "<<f<<std::endl;
    return f;
}
