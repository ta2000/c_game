#include <stdio.h>

#include "player.h"
#include "gameobject.h"

void Player_init(struct Player * p, int x, int y, int speed)
{
    p->base.x = x;
    p->base.y = y;
    p->speed = speed;
}

void Player_print(struct Player * p)
{
    GameObject_print(&(p->base));
    printf("Player speed: %d \n", p->speed);
}
