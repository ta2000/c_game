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

	}
	else if (key == 'u')
	{

	} 
	else if (key == 'm')
	{

	}
}
