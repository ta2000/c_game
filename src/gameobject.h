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

// Save gameobject data
void GameObject_serializeData(
	struct GameObject * self,
	unsigned char * buffer,
	int * index
);
// Load gameobject data
void GameObject_deserializeData(
	struct GameObject * self,
	unsigned char * buffer,
	int * index
);

// Save gameobject state
void GameObject_serializeState(
	struct GameObject * self,
	unsigned char * buffer,
	int * index
);
// Load gameobject state
void GameObject_deserializeState(
	struct GameObject * self,
	unsigned char * buffer,
	int * index
);

#endif
