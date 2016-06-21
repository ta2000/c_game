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
	
	self->nextUnloadedProduct = 0;

	// Clear out products array
	memset(self->products, 0, sizeof(self->products));
	// Clear out costs array
	memset(self->costs, 0, sizeof(self->costs));
}

void Factory_loadData(
	struct Factory * self,
	struct Factory * parent)
{
	strcpy(self->name, parent->name);
	self->base.maxHp = parent->base.maxHp;
	self->cost = parent->cost;
	memcpy(self->products, parent->products, sizeof(self->products));
	memcpy(self->costs, parent->costs, sizeof(self->costs));
	self->speed = parent->speed;	
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
	// Abort if selectedUnit is out of range
	if (selectedUnit >
			sizeof(self->products)/sizeof(self->products[0]) ||
		selectedUnit < 
			0)
	{
		return;
	}

	// Abort and show message if not enough metal
	if ( owner->metal < self->costs[selectedUnit] )
	{
		printf( "Need %d more metal for %s.\n",
			(self->costs[selectedUnit] - owner->metal),
			self->products[selectedUnit].name
		);
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
		printf("Producing %s at %s (-%d metal).\n",
			self->products[selectedUnit].name,
			self->name,
			self->costs[selectedUnit]
		);
		owner->metal -= self->costs[selectedUnit];
	}
	// If unsuccessful
	else
	{
		printf("Unit limit reached.\n");
	}
}

void Factory_update(struct Factory * self)
{
    printf("Updating %s [%.2f,%.2f].\n", self->name, self->base.x, self->base.y);
}
