#include <stdio.h>
#include <string.h>

#include "gameobject.h"
#include "unit.h"
#include "unitpool.h"
#include "factory.h"
#include "factorypool.h"

void Factorypool_init(struct Factorypool * self)
{
    int i;
    for (i = 0; i < sizeof(self->factories)/sizeof(self->factories[0]); i++)
    {
        Factory_init( &(self->factories[i]) );
    }
}

_Bool Factorypool_create(struct Factorypool * self, float x, float y, struct Factory * parent)
{
    struct Factory* factory;
	factory = Factorypool_getNextFactory(self);
	
	if (factory != NULL)
    {
		Factory_create(factory, x, y);
		Factory_loadAttributes(
			factory,
			parent
		);
		return 1;
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

struct Factory* Factorypool_getNextFactory(struct Factorypool * self)
{
    int i;
    for (i = 0; i < sizeof(self->factories)/sizeof(self->factories[0]); i++)
    {
        if (!GameObject_inUse( &(self->factories[i].base) ))
        {
            return &(self->factories[i]);
        }
    }
    return NULL;
}

void Factorypool_serialize(struct Factorypool * self, unsigned char * buffer, int * index)
{
	// Factories
	int i;
	for (i=0; i<sizeof(self->factories)/sizeof(self->factories[0]); i++)
	{
		Factory_serializeState( &(self->factories[i]), buffer, index );
	}
}

void Factorypool_deserialize(struct Factorypool * self, unsigned char * buffer, int * index)
{
	// Clear memory before loading
	memset(self->factories, 0, sizeof(self->factories));
	// Factories
	int i;
	for (i=0; i<sizeof(self->factories)/sizeof(self->factories[0]); i++)
	{
		Factory_deserializeState( &(self->factories[i]), buffer, index );
	}
}
