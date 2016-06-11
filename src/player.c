#include <stdio.h>

#include "gameobject.h"
#include "unit.h"
#include "unitpool.h"
#include "player.h"

void Player_init(struct Player * self, int metal, int power)
{
    // Init player properties
    self->metal = metal;
    self->power = power;
    // Init all units in pool
    Unitpool_init( &(self->unitpool) );
    //printf("Metal: %d\nPower: %d\n", self->metal, self->power);
}

void Player_update(struct Player * self)
{
    Unitpool_update( &(self->unitpool) );
}
