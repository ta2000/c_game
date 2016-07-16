#include <stdio.h>
#include <string.h>
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

    Game_init(&game);

	if (Game_deserializeData(&game) == 1)
	{
		Game_run(&game);
	}

    return 0;
}
