#include "sphvtk.hpp"

sphvtk::sphvtk()
{
    //do nothing
    //but we need to set the args manually  
}

sphvtk::sphvtk(double *x,double *y,double *z,double *vx,double *vy,double *vz,double *p,double *rho)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->vx = vx;
    this->vy = vy;
    this->vz = vz;
    this->p = p;
    this->rho = rho;
    this->index = NULL;
    this->infpath = "";
    this->ofpath = "";
    //other information
    //this->num = num;
    this->flag = 0;
    this->num = -1;
}

//directly output method,we can also set the index to output use index
sphvtk::sphvtk(double *x,double *y,double *z,double *vx,double *vy,double *vz,double *p,double *rho,int num)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->vx = vx;
    this->vy = vy;
    this->vz = vz;
    this->p = p;
    this->rho = rho;
    this->index = NULL;
    this->infpath = "";
    this->ofpath = "";
    //other information
    this->flag = 0;
    this->num = num;
}

sphvtk::sphvtk(double *x,double *y,double *z,double *vx,double *vy,double *vz,double *p,double *rho,int *index)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->vx = vx;
    this->vy = vy;
    this->vz = vz;
    this->p = p;
    this->rho = rho;
    this->index = index;
    this->infpath = "";
    this->ofpath = "";
    //other information 
    //this->num = num;
    this->flag = 0;
    this->num = -1;
}

sphvtk::sphvtk(double *x,double *y,double *z,double *vx,double *vy,double *vz,double *p,double *rho,int *index,int num)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->vx = vx;
    this->vy = vy;
    this->vz = vz;
    this->p = p;
    this->rho = rho;
    this->index = index;
    this->infpath = "";
    this->ofpath = "";
    //other information
    this->flag = 0; 
    this->num = num; 
}

void sphvtk::set_num(int num)
{
    if(this->num == -1)
    {
        this->num = num;
    }
    else
    {
        std::cerr << "the num already set!" << std::endl ;
    }
}

int sphvtk::get_num(void)
{
    if(this->num == -1)
    {
        std::cerr << "the num not set!" << std::endl;
        return ERROR;
    }
    else
    {
        return this->num;
    }
}

void sphvtk::set_infpath(std::string infpath)
{
    this->infpath = infpath;
}

void sphvtk::set_ofpath(std::string ofpath)
{
    this->ofpath = ofpath;
}

void sphvtk::set_flag(int f)
{
    //simply implementation
    this->flag = f;
}

void sphvtk::unset_flag(int f)
{
    //simply implementation
    if(f == BIN_FORMAT) this->flag = CHR_FORMAT;
    else if (f == CHR_FORMAT) this->flag = BIN_FORMAT;
}

int sphvtk::check(void)
{
   return SUCCESS;
}

void sphvtk::readvtk(std::string filename)
{

}

void sphvtk::writevtk(std::string filename)
{
    if (this->num == -1) std::cerr << "do not set num!abort!" << std::endl;
    if (this->index != NULL) std::cerr << "do not implement!" << std::endl;
    std::ofstream fd;
    filename = this->ofpath+filename;
    fd.open(filename.c_str());

    fd << "# vtk DataFile Version 3.0" << std::endl;
    fd << "sph data" << std::endl;
    if (this->flag == CHR_FORMAT)fd << "ASCII" << std::endl;
    else fd << "BINARY" << std::endl; //do not implement
    fd << "DATASET UNSTRUCTURED_GRID" << std::endl;
    fd << "POINTS " << this->num << " " << "double" << std::endl;

    for(int i= 0;i<this->num;i++)
    {
        fd << this->x[i] << " " << this->y[i] << " " << this->z[i] << std::endl;
    }

    fd << "POINT_DATA" << " " << this->num << std::endl;

    fd << "SCALARS "<< "density double 1" << std::endl;
    fd << "LOOKUP_TABLE DEFAULT" << std::endl;
    for(int i=0;i<this->num;i++)
    {
        fd << this->rho[i] << std::endl;
    }

    fd << "SCALARS "<< "pressure double 1" << std::endl;
    fd << "LOOKUP_TABLE DEFAULT" << std::endl;
    for(int i=0;i<this->num;i++)
    {
        fd << this->p[i] << std::endl;
    }

    fd << "VECTORS "<< "velocity double" << std::endl;
    for(int i=0;i<this->num;i++)
    {
        fd << this->vx[i] << " " << this->vy[i] << " " << this->vz[i] << std::endl;
    }

}