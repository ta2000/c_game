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

#define _countof(_Array) (sizeof(_Array) / sizeof(_Array[0]))

static struct Game game;

int main(int argc, char *argv[])
{
	/*
	printf("Sizeof struct game is %zu bytes.\n", sizeof(struct Game));
	printf("Sizeof struct unit is %zu bytes.\n", sizeof(struct Unit));
	*/

    Game_create(&game);
	Game_readData(&game);

	int i,j,k,l;
	for (i=0; i< _countof(game.players); i++)
	{
		for (j=0; j< _countof(game.players[i].factorypool.factories[0].products); j++)
		{
			printf("Unit name: %s\n", game.players[i].factorypool.factories[0].products[j].name);
		}
	}

    //Game_run(&game);

    return 0;
}
