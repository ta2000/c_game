#ifndef FACTORY_H_
#define FACTORY_H_

// Forward declaration of Player
struct Player;

struct Factory
{
    struct GameObject base;
	char name[32];
	int cost;
	struct Unit products[10];
	int costs[10];
	unsigned char speed, progress;
};

// Initialize properties used by pool
void Factory_init(struct Factory * self);

// Load data from parent factory
void Factory_loadData(struct Factory * self, struct Factory * parent);

// Initialize remaining properties of factory
void Factory_create(
    struct Factory * self,
    float x, float y
);

// Update the factory
void Factory_update(struct Factory * self);

// Create a unit, subtract resources
void Factory_produceUnit(
	struct Factory * self,
	int selectedUnit,
	struct Player * owner
);

#endif
