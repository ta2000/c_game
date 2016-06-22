#include <stdio.h>

#include "gameobject.h"
#include "unit.h"
#include "unitpool.h"
#include "factory.h"
#include "factorypool.h"
#include "input.h"
#include "player.h"

char getInput()
{
	char key;
	key = getchar();
	getchar();
	return key;
}

void handleInput(struct Player * player)
{
	char key = getInput();
	
	if (key == 'f')
	{
		Player_placeFactory(player, 16, 17, &(player->factoryTypes[1]));
	}
	else if (key == 'u')
	{
		if (player->factorypool.factories[0].base.selected)
		{
			Factory_produceUnit(&player->factorypool.factories[0], 0, player);
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
}
