#ifndef UNIT_H_
#define UNIT_H_

struct Unit
{
    struct GameObject base;
    int velocity, direction;
    _Bool (*inUse)();
};

void Unit_init(
    struct Unit * self,
    int x, int y, int hp,
    int velocity, int direction
);

_Bool Unit_inUse(struct Unit * self);

void Unit_update(struct Unit * self);

#endif
