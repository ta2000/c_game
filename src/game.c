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
#include "player.h"
#include "input.h"
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
		handleInput(self);
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
	fseek(file, 0L, SEEK_END);
	size_t size = ftell(file);
	rewind(file);

	unsigned char * buffer = malloc(size);
	memset(buffer, 0, size);
	int index = 0;

	size_t bytesRead;
	bytesRead = fread(buffer, size, 1, file);

	Game_deserialize(self, buffer, &index);
	free(buffer);

	return 1;
}

void Game_serialize(struct Game * self, unsigned char * buffer, int * index)
{
	int i;
	for (i=0; i<sizeof(self->players)/sizeof(self->players[0]); i++)
	{
		Player_serialize( &(self->players[i]), buffer, index );
	}
}

void Game_deserialize(struct Game * self, unsigned char * buffer, int * index)
{
	int i;
	for (i=0; i<sizeof(self->players)/sizeof(self->players[0]); i++)
	{
		Player_deserialize( &(self->players[i]), buffer, index );
	}
}
