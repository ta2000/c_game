#include <stdio.h>

#include "serialize.h"
#include "gameobject.h"
#include "unit.h"
#include "unitpool.h"
#include "factory.h"
#include "factorypool.h"
#include "input.h"
#include "player.h"

void Player_create(struct Player * self)
{
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

void Player_serialize(struct Player * self, unsigned char * buffer, int * index)
{
	// Metal
	serialize_int(self->metal, buffer, index);
	// Unitpool
	Unitpool_serialize( &(self->unitpool), buffer, index );
	// Factory types
	int i;
	for (i=0; i<sizeof(self->factoryTypes)/sizeof(self->factoryTypes[0]); i++)
	{
		Factory_serialize( &(self->factoryTypes[i]), buffer, index );
	}
	// Factorypool
	Factorypool_serialize( &(self->factorypool), buffer, index );
}
