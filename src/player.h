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

// Save player data
void Player_serializeData(
	struct Player * self,
	unsigned char * buffer,
	int * index
);
// Load player data
void Player_deserializeData(
	struct Player * self,
	unsigned char * buffer,
	int * index
);

// Save player state
void Player_serializeState(
	struct Player * self,
	unsigned char * buffer,
	int * index
);
// Load player state
void Player_deserializeState(
	struct Player * self,
	unsigned char * buffer,
	int * index
);

#endif
