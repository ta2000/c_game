#ifndef UNIT_H_
#define UNIT_H_

struct Unit
{
    struct GameObject base;
    int velocity, direction;
};

void Unit_init(
    struct Unit * self,
    int x, int y, int hp,
    int velocityX, int direction
);

#endif
