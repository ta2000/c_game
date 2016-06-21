#ifndef PLAYER_H_
#define PLAYER_H_

struct Player
{
    int metal;
    struct Unitpool unitpool;
    struct Factorypool factorypool;
};

// Initialize all values of player
void Player_create(struct Player * self, int metal);

// Update controls and unitpool
void Player_update(struct Player * self);

#endif
