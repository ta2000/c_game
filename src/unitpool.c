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

_Bool Unitpool_create(struct Unitpool * self, float x, float y, struct Unit * parent)
{
    int i;
    for (i = 0; i < sizeof(self->units)/sizeof(self->units[0]); i++)
    {
        if (!GameObject_inUse( &(self->units[i].base) ))
        {
            Unit_create( &(self->units[i]), x, y);
			Unit_loadData(
				&(self->units[i]),
				parent
			);
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
        if (GameObject_inUse( &(self->units[i].base) ))
        {
            Unit_update( &(self->units[i]) );
        }
    }
}
