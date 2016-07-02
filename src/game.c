#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <malloc.h>

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

_Bool Game_loadData(struct Game * self)
{
	FILE *file = fopen("assets/data/data.dat", "r");
	
	// File does not exist
	if (file == NULL)
	{
		printf("Could not find data file. Exiting.\n");
		fclose(file);
		return 0;
	}

	// Read file
	size_t bytes_read;
	bytes_read = fread(self, 1, sizeof(*self), file);

	// Incorrect file signature
	/*
	if ()
	{
	}
	*/

	// File size is wrong
	if (bytes_read != sizeof(*self))
	{
		printf("Data file corrupted. Exiting.\n");
		fclose(file);
		return 0;
	}

	fclose(file);

	return 1;
}
