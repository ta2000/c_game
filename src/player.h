#ifndef PLAYER_H_
#define PLAYER_H_

struct Player
{
    int metal;
    int power;
    struct Unitpool unitpool;
    // Do input stuff now
};

// Initialize all values of player
void Player_create(struct Player * self, int metal, int power);

// Update controls and unitpool
void Player_update(struct Player * self);

#endif
