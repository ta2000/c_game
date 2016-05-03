#include <stdio.h>
#include "gameobject.h"
#include "player.h"

int main(int argc, char *argv[])
{
    struct GameObject myObj;
    GameObject_init(&myObj, 10, 25);
    GameObject_print(&myObj);

    struct Player bob;
    Player_init(&bob, 5, 6, 22);
    Player_print(&bob);
    return 0;
}
