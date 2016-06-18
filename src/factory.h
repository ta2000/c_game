#ifndef FACTORY_H_
#define FACTORY_H_

// Forward declaration of Player
struct Player;

struct Factory
{
    struct GameObject base;
	struct Unit * products;
    int producing, progress;
};

// Initialize properties used by pool
void Factory_init(struct Factory * self);

// Initialize remaining properties of factory
void Factory_create(
    struct Factory * self,
    float x, float y, int hp, int cost,
	struct Unit * products
);

// Update the factory
void Factory_update(struct Factory * self);

// Create a unit, subtract resources
void Factory_produceUnit(struct Factory * self, int selectedUnit, struct Player * owner);


#endif
