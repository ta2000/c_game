#include <stdio.h>
#include <string.h>

#include "gameobject.h"
#include "unit.h"

void Unit_init(struct Unit * self)
{
    GameObject_init( &(self->base) );
}

void Unit_loadData(
	struct Unit * self,
	struct Unit * parent
)
{
	strcpy(self->name, parent->name);
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
    printf("Updating Unit %p [%.2f,%.2f]\n", self, self->base.x, self->base.y);
}
