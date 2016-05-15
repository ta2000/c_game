#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

struct GameObject
{
    int x, y;
    void (*init)(void * self);
    void (*update)(void * self);
    void (*render)(void * self);
    void (*print)(void * self);
};

void GameObject_init(void * self);
void GameObject_update(void * self);
void GameObject_render(void * self);
void GameObject_print(void * self);

#endif
