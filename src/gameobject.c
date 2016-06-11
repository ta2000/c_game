#include <stdio.h>

#include "gameobject.h"

void GameObject_init(struct GameObject * self)
{
    self->hp = 0;
}

void GameObject_create(struct GameObject * self, int x, int y, int hp)
{
    self->x = x;
    self->y = y;
    self->hp = hp;
    //printf("x: %d\ny: %d\nhp: %d\n", self->x, self->y, self->hp);
}
