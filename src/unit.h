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

// Load data from factory preset
void Unit_loadData(
	struct Unit * self,
	char * name,
	int maxHp,
	int maxVelocity,
	int damage,
	int range,
	unsigned char firerate,
	unsigned char shieldRadius
);

// Initialize remaining properties of unit
void Unit_create(
    struct Unit * self,
    float x, float y
);

// Update the unit
void Unit_update(struct Unit * self);

#endif
