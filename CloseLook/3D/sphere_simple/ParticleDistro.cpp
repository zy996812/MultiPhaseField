// distributes particles in randomly
//#include "ParticleDistro.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

//#include "sphere.h"
#include "sphere.cpp"
// #include "peribc.cpp"

double *ParticleDistro(int mboxsize, int nboxsize, int kboxsize, double Pf, int Pr)
{ 
  int particlesn=int(Pf*mboxsize*nboxsize*kboxsize/(4/3*3.1415*Pr*Pr*Pr)); // number of particles
 // cout <<"Number of particles are" << particlesn << endl;

  int nn,ii,jj,kk; //random indexes
  int i,j,k; // loops
  int iind,jind,kind; //periodic indexes
  double irand,jrand,prand, krand;
  double *ppfi;
  double *sphi;
  sphi=sphere(Pr);
  ppfi=new double[mboxsize*nboxsize*kboxsize];
  for (k=0;k<kboxsize;k++)
  {
    for (j=0;j<nboxsize;j++)
    {
      for (i=0;i<mboxsize;i++)
      {
        ppfi[i+j*mboxsize+k*mboxsize*nboxsize]=0;
      }
    }
  }
  
  for (nn=0;nn<particlesn;nn++){
    irand=rand();
    jrand=rand();
    krand=rand();
    prand=rand();
    // these are random index of the top corner of a box contaning the particle.
    // The box is generated by sphere.cpp 
    ii=int((nboxsize*irand)/RAND_MAX);
    jj=int((mboxsize*jrand)/RAND_MAX);
    kk=int((kboxsize*krand)/RAND_MAX);
    for (i=0;i<2*Pr;i++)
    {
      iind=peribc(ii+i,mboxsize);
      for (j=0;j<2*Pr;j++)
      {
        jind=peribc(jj+j,mboxsize);
        for (k=0;k<2*Pr;k++)
        {
          kind=peribc(kk+k,mboxsize);
          ppfi[(iind)+(jind)*mboxsize+(kind)*mboxsize*nboxsize]=sphi[i+j*2*Pr+k*2*Pr*2*Pr];
        }
      }
    }
  }
 
return ppfi;
}
