#ifndef UNIT_H_
#define UNIT_H_

struct Unit
{
    struct GameObject base;
	char name[32];
    int maxVelocity, direction;
	float velocity;
	float targetX, targetY;
	int damage, range;
	unsigned char firerate;
	unsigned char shieldRadius, shieldHealth;
};

// Initialize properties used by pool
void Unit_init(struct Unit * self);

// Load attributes from parent unit
void Unit_loadAttributes(
	struct Unit * self,
	struct Unit * parent
);

// Initialize remaining properties of unit
void Unit_create(
    struct Unit * self,
    float x, float y
);

// Update the unit
void Unit_update(struct Unit * self);

// Serialize unit object
void Unit_serialize(
	struct Unit * self,
	unsigned char * buffer,
	int * index
);

// Deserialize unit object
void Unit_deserialize(
	struct Unit * self,
	unsigned char * buffer,
	int * index
);

#endif
