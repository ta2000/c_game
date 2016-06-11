#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

struct GameObject
{
    int x, y, hp;
};

void GameObject_init(struct GameObject * self);

void GameObject_create(struct GameObject * self, int x, int y, int hp);

#endif
