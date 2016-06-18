#include <stdio.h>

#include "gameobject.h"
#include "unit.h"
#include "unitpool.h"
#include "factory.h"
#include "factorypool.h"
#include "player.h"

void Factory_init(struct Factory * self)
{
    GameObject_init( &(self->base) );
}

void Factory_create(
    struct Factory * self,
	float x, float y, int hp, int cost,
	struct Unit * products)
{
    // Call parent create
    GameObject_create( &(self->base), x, y, hp, cost );
    // Init factory properties
    self->producing = -1;
    self->progress = 0;
	self->products = products;

	self->base.selected = 1; // Remove this later
}

void Factory_produceUnit(struct Factory * self, int selectedUnit, struct Player * owner)
{
	// Abort if the player doesn't have enough metal
	if ( owner->metal < self->products[selectedUnit].base.cost )
	{
		printf( "Need %d more metal for unit.\n", (self->products[selectedUnit].base.cost - owner->metal) );
		return;
	}

	// Try to create a unit
	if ( Unitpool_create(
			&(owner->unitpool),
			self->base.x,
			self->base.y,
			self->products[selectedUnit].base.hp,
			self->products[selectedUnit].base.cost,
			self->products[selectedUnit].velocity,
			self->products[selectedUnit].direction
		) == 1 )
	// If successful
	{
		owner->metal -= self->products[selectedUnit].base.cost;
	}
	// If unsuccessful
	else
	{
		printf("Unit cap reached.\n");
	}
}

void Factory_update(struct Factory * self)
{
    printf("Updating Factory %p [%.2f,%.2f].\n", self, self->base.x, self->base.y);
}
