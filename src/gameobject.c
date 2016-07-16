#include <stdio.h>

#include "serialize.h"
#include "gameobject.h"

void GameObject_init(struct GameObject * self)
{
    self->hp = 0;
}

void GameObject_create(struct GameObject * self, float x, float y)
{
    self->x = x;
    self->y = y;
	self->hp = 1;
	self->selected = 0;
}

_Bool GameObject_inUse(struct GameObject * self)
{
    return self->hp > 0;
}

/*
void _serializeData/_deserializeData()
{
	No data only properties to serialize/deserialize,
	call _serialize()/_deserialize instead
}
*/

void GameObject_serializeData(struct GameObject * self, unsigned char * buffer, int * index)
{
	// Max HP
	serialize_int(self->maxHp, buffer, index);
}

void GameObject_deserializeData(struct GameObject * self, unsigned char * buffer, int * index)
{
	// Max HP
	deserialize_int( &(self->maxHp), buffer, index );
}

void GameObject_serializeState(struct GameObject * self, unsigned char * buffer, int * index)
{
	// X
	serialize_float(self->x, buffer, index);
	// Y
	serialize_float(self->y, buffer, index);
	// HP
	serialize_int(self->hp, buffer, index);
	// Max HP
	GameObject_serializeData(self, buffer, index);
}

void GameObject_deserializeState(struct GameObject * self, unsigned char * buffer, int * index)
{
	// X
	deserialize_float( &(self->x), buffer, index );
	// Y
	deserialize_float( &(self->y), buffer, index );
	// HP
	deserialize_int( &(self->hp), buffer, index );
	// Max HP
	GameObject_deserializeData(self, buffer, index);
}
