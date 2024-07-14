#ifndef __DATASTRUCT_H__
#define __DATASTRUCT_H__

class sphvtk
{
private:
    double *x;
    double *y;
    double *z;
    double *vx;
    double *vy;
    double *vz;
    double *p;
    double *m;
    double *rho;
    int *index;
    unsigned int num;
public:
    sphvtk();
    sphvtk(double *,double *,double *,double *,double *,double *,double *,double *);//x y z vx vy vz p rho
    sphvtk(double *,double *,double *,double *,double *,double *,double *,double *,int *);//x y z vx vy vz p rho index
};

#endif