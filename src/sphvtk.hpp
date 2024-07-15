#ifndef __DATASTRUCT_H__
#define __DATASTRUCT_H__

#define BIN_FORMAT 1
#define CHR_FORMAT 0

#define SUCCESS 0
#define ERROR 1

#include <string>
#include <iostream>
#include <fstream>

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
    int num;
    int flag;
    std::string infpath;
    std::string ofpath;
public:
    sphvtk();
    sphvtk(double *,double *,double *,double *,double *,double *,double *,double *);//x y z vx vy vz p rho
    sphvtk(double *,double *,double *,double *,double *,double *,double *,double *,int);//x y z vx vy vz p rho num
    sphvtk(double *,double *,double *,double *,double *,double *,double *,double *,int *);//x y z vx vy vz p rho index
    sphvtk(double *,double *,double *,double *,double *,double *,double *,double *,int *,int);//x y z vx vy vz p rho index num
    
    void readvtk(std::string);
    void writevtk(std::string);

    void set_num(int);
    int get_num(void);
    void set_infpath(std::string);
    void set_ofpath(std::string);

    void set_flag(int);
    void unset_flag(int);

    int check(void);
};

#endif