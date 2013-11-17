#include <math.h>
// #include "sphere.h"

double *sphere(int radius)
{
double *matsphe;
matsphe= new double[(2*radius)*(2*radius)*(2*radius)];
int i,j,k;
for (k=0;k<2*radius;k++)
{
  for(j=0;j<2*radius;j++)
  {
    for(i=0;i<2*radius;i++)
    {
      if (((i-radius+1)*(i-radius+1)+(j-radius+1)*(j-radius+1)+(k-radius+1)*(k-radius+1))<radius*radius)
      {
        matsphe[i+j*2*radius+k*2*radius*2*radius]=1;
      }
      else
      {
        matsphe[i+j*2*radius+k*2*radius*2*radius]=0;
      }
    }
  }
}
return matsphe;
}
