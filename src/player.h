#ifndef PLAYER_H_
#define PLAYER_H_

struct Player
{
    int metal;
    struct Unitpool unitpool;
    struct Factorypool factorypool;
	struct Unit testProducts[10];
};

// Initialize all values of player
void Player_create(struct Player * self, int metal);

// Update controls and unitpool
void Player_update(struct Player * self);

// Creates a factory at x,y
void Player_placeFactory(struct Player * self, float x, float y, int hp, int cost);
// Tells all selected factories to create a unit
void Player_produceUnits(struct Player * self);
// Tell all selected units to start moving to x,y
void Player_moveUnits(struct Player * self, float x, float y);
// Select unit at x,y
//void Player_selectUnit(struct Player * self, float x, float y);

#endif
