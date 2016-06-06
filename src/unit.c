#include <stdio.h>

#include "gameobject.h"
#include "unit.h"

void Unit_init(
    struct Unit * self,
    int x, int y, int hp,
    int velocity, int direction)
{
    // Call parent init
    GameObject_init( (struct GameObject *)self, x, y, hp );
    // Init unit properties
    self->velocity = velocity;
    self->direction = direction;
    //printf("direction: %d\nvelocity: %d\n", self->velocity, self->direction);
    // Map functions
    self->inUse = Unit_inUse;
}

_Bool Unit_inUse(struct Unit * self)
{
    return self->base.hp > 0;
}

void Unit_update(struct Unit * self)
{
    printf("Updating unit at [%d,%d]\n", self->base.x, self->base.y);
}
