#include <stdio.h>

#include "gameobject.h"
#include "unit.h"

void Unit_init(struct Unit * self)
{
    GameObject_init( &(self->base) );
}

void Unit_create(
    struct Unit * self,
    float x, float y, int hp, int cost,
    int velocity, int direction)
{
    // Call parent create
    GameObject_create( &(self->base), x, y, hp, cost );
    // Init unit properties
    self->velocity = velocity;
    self->direction = direction;
    self->targetX = x;
    self->targetY = y;
}

void Unit_update(struct Unit * self)
{
    printf("Updating Unit %p [%.2f,%.2f]\n", self, self->base.x, self->base.y);
}
