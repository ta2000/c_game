#include <stdio.h>

#include "gameobject.h"
#include "unit.h"

void Unit_init(struct Unit * self)
{
    GameObject_init( &(self->base) );
}

void Unit_create(
    struct Unit * self,
    int x, int y, int hp,
    int velocity, int direction)
{
    // Call parent init
    GameObject_create( &(self->base), x, y, hp );
    // Init unit properties
    self->velocity = velocity;
    self->direction = direction;
    self->selected = 0;
    //printf("direction: %d\nvelocity: %d\n", self->velocity, self->direction);
}

_Bool Unit_inUse(struct Unit * self)
{
    return self->base.hp > 0;
}

void Unit_update(struct Unit * self)
{
    printf("Updating Unit %p [%d,%d]\n", self, self->base.x, self->base.y);
}
