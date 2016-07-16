#include <stdio.h>
#include <string.h>

#include "serialize.h"
#include "gameobject.h"
#include "unit.h"
#include "unitpool.h"
#include "factory.h"
#include "factorypool.h"
#include "player.h"

void Factory_init(struct Factory * self)
{
    GameObject_init( &(self->base) );
	
	// Clear out products array
	memset(self->products, 0, sizeof(self->products));
	// Clear out costs array
	memset(self->costs, 0, sizeof(self->costs));
}

void Factory_loadAttributes(
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


void Factory_serializeData(struct Factory * self, unsigned char * buffer, int * index)
{
	GameObject_serializeData( &(self->base), buffer, index );
	Factory_serialize(self, buffer, index);
}

void Factory_deserializeData(struct Factory * self, unsigned char * buffer, int * index)
{
	GameObject_deserializeData( &(self->base), buffer, index );
	Factory_deserialize(self, buffer, index);
}

void Factory_serializeState(struct Factory * self, unsigned char * buffer, int * index)
{	
	GameObject_serializeState( &(self->base), buffer, index );
	Factory_serialize(self, buffer, index);
}

void Factory_deserializeState(struct Factory * self, unsigned char * buffer, int * index)
{
	GameObject_deserializeState( &(self->base), buffer, index );
	Factory_deserialize(self, buffer, index);
}

void Factory_serialize(struct Factory * self, unsigned char * buffer, int * index)
{
	// Name
	serialize_string(self->name, sizeof(self->name), buffer, index);
	// Cost
	serialize_int(self->cost, buffer, index);
	// Products
	int i;
	for (i=0; i<sizeof(self->products)/sizeof(self->products[0]); i++)
	{
		Unit_serializeData( &(self->products[i]), buffer, index );
	}
	// Costs of products
	for (i=0; i<sizeof(self->costs)/sizeof(self->costs[0]); i++)
	{
		serialize_int(self->costs[i], buffer, index);
	}
	// Speed
	serialize_char(self->speed, buffer, index);
}

void Factory_deserialize(struct Factory * self, unsigned char * buffer, int * index)
{
	// Name
	deserialize_string(self->name, sizeof(self->name), buffer, index);
	// Cost
	deserialize_int( &(self->cost), buffer, index );
	// Products
	int i;
	for (i=0; i<sizeof(self->products)/sizeof(self->products[0]); i++)
	{
		Unit_deserializeData( &(self->products[i]), buffer, index );
	}
	// Costs of products
	for (i=0; i<sizeof(self->costs)/sizeof(self->costs[0]); i++)
	{
		deserialize_int( &(self->costs[i]), buffer, index );
	}
	// Speed
	deserialize_uchar( &(self->speed), buffer, index );
}
