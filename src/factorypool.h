#ifndef FACTORYPOOL_H_
#define FACTORYPOOL_H_

struct Factorypool
{
    struct Factory factories[3];
	int nextAvailableFactory;
};

// Initialize hp of all units for inUse function
void Factorypool_init(struct Factorypool * self);

// Get unused factory and assign properties
// Returns 1 if factory was created, 0 if all factories in use
_Bool Factorypool_create(
    struct Factorypool * self,
    float x, float y
);

// Update all units currently in use
void Factorypool_update(struct Factorypool * self);

#endif
