#ifndef UNITPOOL_H_
#define UNITPOOL_H_

struct Unitpool
{
    struct Unit units[3];
};

// Initialize hp of all units for inUse function
void Unitpool_init(struct Unitpool * self);

// Initialize remaining properties of all units
// Returns 1 if unit was created, 0 if all units in use
_Bool Unitpool_create(
    struct Unitpool * self,
    float x, float y, int hp, int cost,
    int velocity, int direction
);

// Update all units currently in use
void Unitpool_update(struct Unitpool * self);

#endif
