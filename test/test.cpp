#include "../src/sphio.h"

int main(void)
{
    double x[8] = {0};
    sphvtk ok(x,x+1,x+2,x+3,x+4,x+5,x+6,x+7);
    return 0;
}