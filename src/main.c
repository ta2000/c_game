#include <stdio.h>
#include <malloc.h>

#include "player.h"
#include "gameobject.h"
#include "unit.h"
#include "game.h"

struct Game game;

int main(int argc, char *argv[])
{
    Game_init(&game);
    Game_run(&game);

    return 0;
}
