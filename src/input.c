#include <stdio.h>

#include "gameobject.h"
#include "unit.h"
#include "unitpool.h"
#include "factory.h"
#include "factorypool.h"
#include "player.h"
#include "game.h"
#include "input.h"

char getInput()
{
	char key;
	key = getchar();
	getchar();
	return key;
}

void handleInput(struct Game * game)
{
	char key = getInput();

	// Use temporary pointer to first player
	struct Player * player;
	player = &(game->players[0]);
	
	if (key == 'f')
	{
		Player_placeFactory(player, 16, 17, &(player->factoryTypes[1]));
	}
	else if (key == 'u')
	{
		if (player->factorypool.factories[0].base.selected)
		{
			Factory_produceUnit(&(player->factorypool.factories[0]), 0, player);
		}
		else
		{
			printf("No factories selected.\n");
		}
	}
	else if (key == 'm')
	{
		player->metal+=100;
	}
	else if (key == 's')
	{
		printf("Saving game...\n");
		Game_serializeState(game);
	}
	else if (key == 'l')
	{
		printf("Loading saved game...\n");
		Game_init(game);
		Game_deserializeState(game);
	}
}
