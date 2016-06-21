#ifndef UNITPOOL_H_
#define UNITPOOL_H_

struct Unitpool
{
    struct Unit units[5];
};

// Initialize hp of all units for inUse function
void Unitpool_init(struct Unitpool * self);

// Get unused unit and set properties equal to factory selected unit
// Returns 1 if unit was created, 0 if all units in use
_Bool Unitpool_create(
    struct Unitpool * self,
    float x, float y,
	struct Unit * parent
);

// Update all units currently in use
void Unitpool_update(struct Unitpool * self);

#endif
