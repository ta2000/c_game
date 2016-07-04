#ifndef FACTORYPOOL_H_
#define FACTORYPOOL_H_

struct Factorypool
{
    struct Factory factories[3];
};

// Initialize hp of all units for inUse function
void Factorypool_init(struct Factorypool * self);

// Get unused factory and assign properties
// Returns 1 if factory was created, 0 if all factories in use
_Bool Factorypool_create(
    struct Factorypool * self,
    float x, float y,
	struct Factory * parent
);

// Update all units currently in use
void Factorypool_update(struct Factorypool * self);

// Return address of next !inUse factory
struct Factory* Factorypool_getNextFactory(struct Factorypool * self);

// Serialize factorypool object
void Factorypool_serialize(
	struct Factorypool * self,
	unsigned char * buffer,
	int * index
);

#endif
