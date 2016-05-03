#ifndef PLAYER_H_
#define PLAYER_H_

#include "gameobject.h"

struct Player
{
    struct GameObject base;
    int speed;
};

void Player_init(struct Player * p, int x, int y, int speed);
void Player_print(struct Player * p);

#endif
