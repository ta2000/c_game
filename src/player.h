#ifndef PLAYER_H_
#define PLAYER_H_

struct Player
{
    int metal;
    int power;
    struct Unitpool unitpool;
    // Do input stuff now
};

void Player_init(
    struct Player * self,
    int metal, int power
);

#endif
