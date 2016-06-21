#include <stdio.h>

#include "gameobject.h"
#include "unit.h"
#include "unitpool.h"
#include "factory.h"
#include "factorypool.h"

void Factorypool_init(struct Factorypool * self)
{
	self->nextAvailableFactory = 0;

    int i;
    for (i = 0; i < sizeof(self->factories)/sizeof(self->factories[0]); i++)
    {
        Factory_init( &(self->factories[i]) );
    }
}

_Bool Factorypool_create(struct Factorypool * self, float x, float y)
{
    int i;
    for (i = 0; i < sizeof(self->factories)/sizeof(self->factories[0]); i++)
    {
        if (!GameObject_inUse( &(self->factories[i].base) ))
        {
            Factory_create( &(self->factories[i]), x, y);
            return 1;
        }
    }
    return 0;
}

void Factorypool_update(struct Factorypool * self)
{
    int i;
    for (i = 0; i < sizeof(self->factories)/sizeof(self->factories[0]); i++)
    {
        if (GameObject_inUse( &(self->factories[i].base) ))
        {
            Factory_update( &(self->factories[i]) );
        }
    }
}
