#ifndef UNITPOOL_H_
#define UNITPOOL_H_

struct Unitpool
{
    struct Unit units[3];
};

void Unitpool_init(struct Unitpool * self);

void Unitpool_create(
    struct Unitpool * self,
    int x, int y, int hp,
    int velocity, int direction
);

void Unitpool_update(struct Unitpool * self);

#endif
