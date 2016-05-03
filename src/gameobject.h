#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

struct GameObject
{
    int x, y;
};

void GameObject_init(struct GameObject * GO, int x, int y);
void GameObject_print(struct GameObject * GO);

#endif
