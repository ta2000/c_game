#include <stdio.h>

#include "gameobject.h"

void GameObject_init(struct GameObject * self)
{
    self->hp = 0;
}

void GameObject_create(struct GameObject * self, float x, float y)
{
    self->x = x;
    self->y = y;
	self->hp = 1;
	self->selected = 0;
}

_Bool GameObject_inUse(struct GameObject * self)
{
    return self->hp > 0;
}
