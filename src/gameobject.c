#include <stdio.h>

#include "gameobject.h"

void GameObject_init(void * self)
{
    struct GameObject * obj = self;
    obj->x = 10;
    obj->y = 10;
}

void GameObject_update(void * self)
{

}

void GameObject_render(void * self)
{

}

void GameObject_print(void * self)
{
    struct GameObject * obj = self;
    printf("GameObject location: [%d,%d]\n", obj->x, obj->y);
}
