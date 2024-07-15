#include "../src/sphio.hpp"

int main(void)
{
    double x[8] = {0};
    sphvtk ok(x,x+1,x+2,x+3,x+4,x+5,x+6,x+7);
    ok.set_num(1);
    std::string fpath = "./";
    std::string filename = "ok.vtk";
    ok.set_ofpath(fpath);
    ok.writevtk(filename);
    return 0;
}