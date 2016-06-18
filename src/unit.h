#ifndef UNIT_H_
#define UNIT_H_

struct Unit
{
    struct GameObject base;
    int velocity, direction;
	float targetX, targetY;
};

// Initialize properties used by pool
void Unit_init(struct Unit * self);

// Initialize remaining properties of unit
void Unit_create(
    struct Unit * self,
    float x, float y, int hp, int cost,
    int velocity, int direction
);

// Update the unit
void Unit_update(struct Unit * self);

#endif
