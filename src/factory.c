#include <stdio.h>
#include <string.h>

#include "gameobject.h"
#include "unit.h"
#include "unitpool.h"
#include "factory.h"
#include "factorypool.h"
#include "player.h"

void Factory_init(struct Factory * self)
{
    GameObject_init( &(self->base) );
	
	self->nextAvailableProduct = 0;

	// Clear out products array
	memset(self->products, 0, sizeof(self->products));
	// Clear out costs array
	memset(self->costs, 0, sizeof(self->costs));
}

void Factory_loadData(
	struct Factory * self,
	int maxHp, int cost,
	unsigned char speed,
	struct Unit * products,
	int * costs)
{
	self->base.maxHp = maxHp;
	self->speed = speed;	

	memcpy(self->products, products, sizeof(self->products));
	memcpy(self->costs, costs, sizeof(self->costs));
}

void Factory_create(
    struct Factory * self,
	float x, float y)
{
    // Call parent create
    GameObject_create( &(self->base), x, y );
    // Init factory properties
    self->progress = 0;

	self->base.selected = 1; // Remove this later
}

void Factory_produceUnit(struct Factory * self, int selectedUnit, struct Player * owner)
{
	// Abort and show message if not enough metal
	if ( owner->metal < self->costs[selectedUnit] )
	{
		printf( "Need %d more metal for unit.\n", (self->costs[selectedUnit] - owner->metal) );
		return;
	}

	// Try to create a unit
	if ( Unitpool_create(
			&(owner->unitpool),
			self->base.x,
			self->base.y,
			&(self->products[selectedUnit])
		) == 1 )
	// If successful
	{
		owner->metal -= self->costs[selectedUnit];
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
