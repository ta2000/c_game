#ifndef FACTORYPOOL_H_
#define FACTORYPOOL_H_

struct Factorypool
{
    struct Factory factories[3];
};

// Initialize hp of all units for inUse function
void Factorypool_init(struct Factorypool * self);

// Initialize remaining properties of all factories
// Returns 1 if factory was created, 0 if all factories in use
_Bool Factorypool_create(
    struct Factorypool * self,
    float x, float y, int hp, int cost,
	struct Unit * products
);

// Update all units currently in use
void Factorypool_update(struct Factorypool * self);

#endif
