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

	// Temp
	int i;
	for (i=0; i<sizeof(self->testProducts)/sizeof(self->testProducts[0]); i++)
	{
		Unit_init( &(self->testProducts[i]) );
		Unit_create( &(self->testProducts[i]), 8, 9, 20, 10, 0, 0 );
	}
}

void Player_update(struct Player * self)
{
	handleInput(self);
    Unitpool_update( &(self->unitpool) );
    Factorypool_update( &(self->factorypool) );
}



/******************************************
** Functions to interface with game objects
******************************************/

void Player_placeFactory(struct Player * self, float x, float y, int hp, int cost)
{
	// Abort if the player doesn't have enough metal
	if (self->metal < cost)
	{
		printf("Need %d more metal for factory.\n", cost - self->metal);
		return;
	}

	if ( Factorypool_create(
			&(self->factorypool),
			x, y, hp, cost,
			self->testProducts
	) == 1)
	// If successful
	{
		self->metal -= cost;
	}
	// If unsuccessful
	else
	{
		printf("Factory cap reached.\n");
	}
}

void Player_produceUnits(struct Player * self)
{
	_Bool factoriesSelected = 0;

	int i;
	for (i=0; i<sizeof(self->factorypool.factories)/sizeof(self->factorypool.factories[0]); i++)
	{
		if ( GameObject_inUse( &(self->factorypool.factories[i].base) ) )
		{
			factoriesSelected = 1;
			Factory_produceUnit( &(self->factorypool.factories[i]), 0, self);
		}
	}

	if (factoriesSelected == 0)
	{
		printf("No factories selected");
	}
}

void Player_moveUnits(struct Player * self, float x, float y)
{
	int i;
	for (i=0; i<sizeof(self->unitpool.units)/sizeof(self->unitpool.units[0]); i++)
	{
		self->unitpool.units[i].targetX = x;
		self->unitpool.units[i].targetY = y;
	}
}

/*void Player_selectUnit(struct Player * self, float x, float y)
{
	int i;
	for (i=0; i<sizeof(self->unitpool.units)/sizeof(self->unitpool.units[0]); i++)
	{
		
	}
}*/

