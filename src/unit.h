#ifndef UNIT_H_
#define UNIT_H_

struct Unit
{
    struct GameObject base;
    int velocity, direction;
    _Bool selected;
};

// Initialize hp of unit for inUse function
void Unit_init(struct Unit * self);

// Initialize remaining properties of unit
void Unit_create(
    struct Unit * self,
    int x, int y, int hp,
    int velocity, int direction
);

// Return whether health is greater than 0
_Bool Unit_inUse(struct Unit * self);

// Update the unit
void Unit_update(struct Unit * self);

#endif
