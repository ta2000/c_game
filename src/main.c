#include <stdio.h>
#include <malloc.h>

#include "gameobject.h"
#include "unit.h"
#include "unitpool.h"
#include "factory.h"
#include "factorypool.h"
#include "input.h"
#include "player.h"

#include "game.h"

static struct Game game;

int main(int argc, char *argv[])
{
	
	//printf("Sizeof struct game is %zu bytes.\n", sizeof(game));

    Game_create(&game);
	Game_loadData(&game);
	Game_run(&game);

    return 0;
}
