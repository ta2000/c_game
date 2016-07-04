#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

struct GameObject
{
    float x, y;
	int hp, maxHp;
	_Bool selected;
};

// Initialize properties used by pool
void GameObject_init(struct GameObject * self);

// Initialize remaining properties of gameobject
void GameObject_create(struct GameObject * self, float x, float y);

// Return whether health is greater than 0
_Bool GameObject_inUse(struct GameObject * self);

// Serialize gameobject object
void GameObject_serialize(
	struct GameObject * self,
	unsigned char * buffer,
	int * index
);

#endif
