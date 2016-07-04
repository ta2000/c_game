#ifndef PLAYER_H_
#define PLAYER_H_

struct Player
{
    int metal;
    struct Unitpool unitpool;
	struct Factory factoryTypes[6];
    struct Factorypool factorypool;
};

// Initialize all values of player
void Player_create(struct Player * self);

// Update controls and unitpool
void Player_update(struct Player * self);

// Attempt to create a factory, checking for issues
void Player_placeFactory(
	struct Player * self,
	float x, float y,
	struct Factory * parent
);

// Serialize player object
void Player_serialize(
	struct Player * self,
	unsigned char * buffer,
	int * index
);

#endif
