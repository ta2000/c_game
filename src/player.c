#include <stdio.h>
#include "player.h"

void Player_init(
    struct Player * self,
    int metal, int power)
{
    // Init unit properties
    self->metal = metal;
    self->power = power;
    printf("Metal: %d\nPower: %d\n", self->metal, self->power);
}
