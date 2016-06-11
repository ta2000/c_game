#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

struct GameObject
{
    int x, y, hp;
};

// Initialize hp of unit for inUse function
void GameObject_init(struct GameObject * self);

// Initialize remaining properties of gameobject
void GameObject_create(struct GameObject * self, int x, int y, int hp);

#endif
