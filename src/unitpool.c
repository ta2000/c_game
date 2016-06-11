#include <stdio.h>

#include "gameobject.h"
#include "unit.h"
#include "unitpool.h"

void Unitpool_init(struct Unitpool * self)
{
    int i;
    for (i = 0; i < sizeof(self->units)/sizeof(self->units[0]); i++)
    {
        Unit_init( &(self->units[i]) );
    }
}

_Bool Unitpool_create(struct Unitpool * self, int x, int y, int hp, int velocity, int direction)
{
    int i;
    for (i = 0; i < sizeof(self->units)/sizeof(self->units[0]); i++)
    {
        if (!Unit_inUse( &(self->units[i]) ))
        {
            Unit_create( &(self->units[i]), x, y, hp, velocity, direction);
            return 1;
        }
    }
    return 0;
}

void Unitpool_update(struct Unitpool * self)
{
    int i;
    for (i = 0; i < sizeof(self->units)/sizeof(self->units[0]); i++)
    {
        if (Unit_inUse( &(self->units[i]) ))
        {
            Unit_update( &(self->units[i]) );
        }
    }
}
