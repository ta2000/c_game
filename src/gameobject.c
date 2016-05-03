#include <stdio.h>

#include "gameobject.h"

void GameObject_init(struct GameObject * GO, int x, int y)
{
    GO->x = x;
    GO->y = y;
}

void GameObject_print(struct GameObject * GO)
{
    printf("GameObject location: [%d,%d]\n", GO->x, GO->y);
}
