#include <stdio.h>
#include <string.h>

#include "serialize.h"
#include "gameobject.h"
#include "unit.h"

void Unit_init(struct Unit * self)
{
    GameObject_init( &(self->base) );

	memset(self->name, '\0', sizeof(self->name));
}

void Unit_loadAttributes(
	struct Unit * self,
	struct Unit * parent)
{
	strcpy(self->name, parent->name);
	self->base.maxHp = parent->base.maxHp;
	self->base.hp = parent->base.maxHp;
	self->maxVelocity = parent->maxVelocity;
	self->damage = parent->damage;
	self->range = parent->range;
	self->firerate = parent->firerate;
	self->shieldRadius = parent->shieldRadius;
}

void Unit_create(
    struct Unit * self,
    float x, float y)
{
    // Call parent create
    GameObject_create( &(self->base), x, y );
    // Init unit properties
    self->targetX = x;
    self->targetY = y;
	self->shieldHealth = 100;
}

void Unit_update(struct Unit * self)
{
    printf("Updating %s [%.2f,%.2f]\n", self->name, self->base.x, self->base.y);
	printf("\tHP: %d\n", self->base.hp);
	printf("\tMax Velocity: %d\n", self->maxVelocity);
	printf("\tDamage: %d\n", self->damage);
	printf("\tRange: %d\n", self->range);
	printf("\tFirerate: %d\n", self->firerate);
	printf("\tShield: %d\n", self->shieldRadius);
}

void Unit_serializeData(struct Unit * self, unsigned char * buffer, int * index)
{
	// Base
	GameObject_serializeData( &(self->base), buffer, index );
	// Remaining attributes
	Unit_serialize(self, buffer, index);
}

void Unit_deserializeData(struct Unit * self, unsigned char * buffer, int * index)
{
	// Base
	GameObject_deserializeData( &(self->base), buffer, index );
	// Remaining attributes
	Unit_deserialize(self, buffer, index);
}

void Unit_serializeState(struct Unit * self, unsigned char * buffer, int * index)
{
	// Base
	GameObject_serializeState( &(self->base), buffer, index );
	// Remaining attributes
	Unit_serialize(self, buffer, index);
}

void Unit_deserializeState(struct Unit * self, unsigned char * buffer, int * index)
{
	// Base
	GameObject_serializeState( &(self->base), buffer, index );
	// Remaining attributes
	Unit_deserialize(self, buffer, index);
}

void Unit_serialize(struct Unit * self, unsigned char * buffer, int * index)
{
	// Name
	serialize_string(self->name, sizeof(self->name), buffer, index);
	// Max velocity
	serialize_int(self->maxVelocity, buffer, index);
	// Damage
	serialize_int(self->damage, buffer, index);
	// Range
	serialize_int(self->range, buffer, index);
	// Firerate
	serialize_char(self->firerate, buffer, index);
	// Shield Radius
	serialize_char(self->shieldRadius, buffer, index);
}

void Unit_deserialize(struct Unit * self, unsigned char * buffer, int * index)
{
	// Name
	deserialize_string(self->name, sizeof(self->name), buffer, index);
	// Max velocity
	deserialize_int( &(self->maxVelocity), buffer, index );
	// Damage
	deserialize_int( &(self->damage), buffer, index );
	// Range
	deserialize_int( &(self->range), buffer, index );
	// Firerate
	deserialize_uchar( &(self->firerate), buffer, index);
	// Shield Radius
	deserialize_uchar( &(self->shieldRadius), buffer, index);
}
