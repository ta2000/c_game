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
    // Init rest
    self->velocity = velocity;
    self->direction = direction;
    printf("direction: %d\nvelocity: %d\n", self->velocity, self->direction);
}

void Unit_move(struct Unit * self)
{

}
