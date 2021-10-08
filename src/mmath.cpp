#include "mmath.h"

u32 mmath::factorial(u16 n) 
{
  u32 f = 1;
  for(u16 i = 1; i <= n; i++) {
    f *= i;
  }
  return f;
}

// exponential function, calculate x^y
double mmath::pow(s16 x, u16 y) 
{
  if (y == 0)
    return 1;
  else if (y%2 == 0)
    return mmath::pow(x, y/2)*mmath::pow(x, y/2);
  else
    return x*mmath::pow(x, y/2)*mmath::pow(x, y/2);
}

// taylor estimation of e^x
double mmath::exp(u16 x) 
{
  double ex = 1;
  for(u16 i = 1; i < x; i++) 
  {
    ex += ( mmath::pow(x, i) / mmath::factorial(i) );
  }
  return ex;
}

// simple sigmoid function
double mmath::sigmoid(double x) 
{
  return ( mmath::exp(x) / ( mmath::exp(x) + 1 ) );
}

auto mmath::min(void *x, void *y) 
{
  if(x <= y) return x;
  else return y;
}
