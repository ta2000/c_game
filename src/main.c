#include <stdio.h>
#include "gameobject.h"

int main(int argc, char *argv[])
{
    struct GameObject myObj;
    GameObject_init(&myObj);
    GameObject_print(&myObj);

    return 0;
}
