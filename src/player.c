#include <stdio.h>

#include "gameobject.h"
#include "unit.h"
#include "unitpool.h"
#include "factory.h"
#include "factorypool.h"
#include "input.h"
#include "player.h"

void Player_create(struct Player * self)
{
	self->nextUnloadedFactory = 0;
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

void Player_placeFactory(struct Player * self, float x, float y, struct Factory * parent)
{
	// Abort and show message if not enough metal
	if (self->metal < parent->cost)
	{
		printf("Need %d more metal for %s.\n",
			(parent->cost - self->metal),
			parent->name
		);
		return;
	}
	
	// Try creating a factory
	if ( Factorypool_create(
			&(self->factorypool),
			x, y, parent
		) == 1 )
	// If successful
	{
		printf("Producing %s (-%d metal).\n",
			parent->name,
			parent->cost
		);
		self->metal -= parent->cost;
	}
	// If unsuccessful
	else
	{
		printf("Factory limit reached.\n");
	}
}
