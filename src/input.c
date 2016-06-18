#include <stdio.h>

#include "gameobject.h"
#include "unit.h"
#include "unitpool.h"
#include "factory.h"
#include "factorypool.h"
#include "input.h"
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
		Player_placeFactory(player, 4, 6, 200, 120);
	}
	else if (key == 'u')
	{
		Player_produceUnits(player);
	} 
	else if (key == 'm')
	{
		Player_moveUnits(player, 0, 0);
	}
	/*else if (key == 's')
	{
		Player_selectUnits(player);
	}*/
}
