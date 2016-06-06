#ifndef PLAYER_H_
#define PLAYER_H_

struct Player
{
    int metal;
    int power;
};

void Player_init(
    struct Player * self,
    int metal, int power
);

#endif
