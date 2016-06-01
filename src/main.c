#include <stdio.h>
#include "gameobject.h"
#include "unit.h"

int main(int argc, char *argv[])
{
    struct Unit tank;
    Unit_init(&tank, 2, 3, 80, 10, 180); 

    return 0;
}
