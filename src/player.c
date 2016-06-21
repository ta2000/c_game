#include <stdio.h>

#include "gameobject.h"
#include "unit.h"
#include "unitpool.h"
#include "factory.h"
#include "factorypool.h"
#include "input.h"
#include "player.h"

void Player_create(struct Player * self, int metal)
{
    // Init player properties
    self->metal = metal;
    // Init all units in pool
    Unitpool_init( &(self->unitpool) );
    // Init all factories in pool
    Factorypool_init( &(self->factorypool) );
}

void Player_update(struct Player * self)
{
	handleInput(self);
    Unitpool_update( &(self->unitpool) );
    Factorypool_update( &(self->factorypool) );
}
