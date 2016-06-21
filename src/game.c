#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

#include "util.h"
#include "gameobject.h"
#include "unit.h"
#include "unitpool.h"
#include "factory.h"
#include "factorypool.h"
#include "input.h"
#include "player.h"
#include "game.h"

void Game_create(struct Game * self)
{
    self->running = 1;

	// Index of first unloaded player struct
    self->nextAvailablePlayer = 0;

	// For reading from file
	self->level = NONE;

    // Init all players in pool
    int i;
    for (i = 0; i < sizeof(self->players)/sizeof(self->players[0]); i++)
    {
        Player_create( &(self->players[i]) );
    }
}

// Game loop
void Game_run(struct Game * self)
{
    int i;
    while (self->running)
    {
        // Update all players
        for (i = 0; i < sizeof(self->players)/sizeof(self->players[0]); i++)
        {
            printf("=== Player %d - Metal: %d ===\n", i+1, self->players[i].metal);
            Player_update( &(self->players[i]) );
        }
        // Newline before next frame
        printf("\n");
        //sleep(2);
    }
}

_Bool Game_readData(struct Game * self)
{
	FILE *file = fopen("assets/data/factions.json", "r");
	
	if (file == NULL)
	{
		printf("Could not find file.\n");
		return 0;
	}
	
	char line[128] = {0};
	while(fgets(line, 128, file) != NULL)
	{
		Game_parseLine(self, line);
		memset(&line[0], '\0', sizeof(line));
	}

	fclose(file);

	return 1;
}

void Game_parseLine(struct Game * self, char * line)
{
	char key[128] = {'\0'};
	char value[128] = {'\0'};
	unsigned char counter = 0;
	_Bool writeTo = 0;

	char lineNew[128] = {'\0'};

	// Remove quotes, spaces, tabs, etc.
	int i, j=0; _Bool inQuotes = 0;
	for (i=0; i<strlen(line); i++)
	{
		if (line[i] == 34)
		{
			inQuotes = !inQuotes; // Flip bool
		}

		if (inQuotes &&
			line[i] != 34 && // Quotes
			line[i] != 9 && // Tab
			line[i] != '\n'
		)
		{
			memcpy(&lineNew[j], &line[i], sizeof(line[i]));
			j++;
		}
		else if (!inQuotes &&
			line[i] != 32 && // Space
			line[i] != 44 && // Comma
			line[i] != 46 && // Period
			line[i] != 34 && // Quotes
			line[i] != 9 && // Tab
			line[i] != '\n'
		)
		{
			memcpy(&lineNew[j], &line[i], sizeof(line[i]));
			j++;
		}
	}

	// Write to key/value
	for (i=0; i<strlen(lineNew); i++)
	{
		if (lineNew[i] == 58)
		{
			writeTo = 1;
			counter = 0;
			i++; // Skip colon
		}
		
		if (writeTo == 0)
		{
			key[counter] = lineNew[i];
		}
		else if (writeTo == 1)
		{
			value[counter] = lineNew[i];
		}
		
		counter++;
	}

	key[127] = '\0';
	value[127] = '\0';

	Game_loadData(self, key, value);
}

void Game_loadData(struct Game * self, char * key, char * value)
{
	// Get next uninitialized player
	struct Player * playerLoading;
	playerLoading = &self->players[self->nextAvailablePlayer];
	// Get next uninitialized factory
	struct Factory * factoryLoading;
	factoryLoading = &playerLoading->factorypool.factories[playerLoading->factorypool.nextAvailableFactory];
	// Get next uninitialized factory product
	struct Unit * unitLoading;
	unitLoading = &factoryLoading->products[factoryLoading->nextAvailableProduct];

	// Start above faction level
	if (self->level == NONE)
	{
		if (strcmp(key, "faction") == 0)
			self->level = FACTION;
	}
	// Set faction data
	if (self->level == FACTION)
	{
		// Metal
		if (strcmp(key, "metal") == 0)
		{
			playerLoading->metal = Util_parse(value, INT_MIN, INT_MAX);
		}
		// Down a level
		else if (strcmp(key, "factory") == 0)
		{
			self->level = FACTORY;
		}
		// Up a level
		else if (strcmp(key, "}") == 0)
		{
			self->level = NONE;
			self->nextAvailablePlayer++;
		}
	}
	// Set factory data
	else if (self->level == FACTORY)
	{
		// Name
		if (strcmp(key, "name") == 0)
		{
			strcpy(factoryLoading->name, value);
		}
		// Cost
		else if (strcmp(key, "cost") == 0)
		{
			factoryLoading->cost = Util_parse(value, INT_MIN, INT_MAX);
		}
		// Speed
		else if (strcmp(key, "speed") == 0)
		{
			factoryLoading->speed = Util_parse(value, CHAR_MIN, CHAR_MAX);
		}
		// Down a level
		else if (strcmp(key, "products") == 0)
		{
			self->level = PRODUCTS;
		}
		// Up a level
		else if (strcmp(key, "}") == 0)
		{
			self->level = FACTION;
			playerLoading->factorypool.nextAvailableFactory++;
		}
	}
	// Set factory products data
	else if (self->level == PRODUCTS)
	{
		// Down a level
		if (strcmp(key, "unit") == 0)
		{
			self->level = UNIT;
		}
		// Up a level
		else if (strcmp(key, "]") == 0)
		{
			self->level = FACTORY;
		}
	}
	// Set individual unit data
	else if (self->level == UNIT)
	{
		if (strcmp(key, "name") == 0)
		{
			Util_strcpy(unitLoading->name, value);
		}
		else if (strcmp(key, "hp") == 0)
		{
			unitLoading->base.maxHp = Util_parse(value, INT_MIN, INT_MAX);
		}
		else if (strcmp(key, "max-velocity") == 0)
		{
			unitLoading->maxVelocity = Util_parse(value, INT_MIN, INT_MAX);
		}
		else if (strcmp(key, "damage") == 0)
		{
			unitLoading->damage = Util_parse(value, INT_MIN, INT_MAX);
		}
		else if (strcmp(key, "firerate") == 0)
		{
			unitLoading->firerate = Util_parse(value, 0, UCHAR_MAX);
		}
		else if (strcmp(key, "range") == 0)
		{
			unitLoading->range = Util_parse(value, INT_MIN, INT_MAX);
		}
		else if (strcmp(key, "sheild") == 0)
		{
			unitLoading->shieldRadius = Util_parse(value, 0, UCHAR_MAX);
		}
		// Up a level
		else if (strcmp(key, "}") == 0)
		{
			self->level = PRODUCTS;
			factoryLoading->nextAvailableProduct++;
		}
	}
}
