#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <malloc.h>

#include "filemanager.h"
#include "gameobject.h"
#include "unit.h"
#include "unitpool.h"
#include "factory.h"
#include "factorypool.h"
#include "player.h"
#include "input.h"
#include "game.h"

void Game_init(struct Game * self)
{
    self->running = 1;

    // Init all players in pool
    int i;
    for (i = 0; i < sizeof(self->players)/sizeof(self->players[0]); i++)
    {
        Player_init( &(self->players[i]) );
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

_Bool Game_serializeData(struct Game * self)
{
	char * dataFile = "assets/data/data.dat";
	size_t fileSize = 3490;//getFileSize(dataFile);

	unsigned char * buffer = calloc(1, fileSize);
	int index = 0;

	// Save data from all players
	int i;
	for (i=0; i<sizeof(self->players)/sizeof(self->players[0]); i++)
	{
		Player_serializeData( &(self->players[i]), buffer, &index );
	}

	// Write buffer into file
	writeFile(dataFile, buffer, fileSize);

	free(buffer);

	return 1;
}

_Bool Game_deserializeData(struct Game * self)
{
	char * dataFile = "assets/data/data.dat";
	size_t fileSize = getFileSize(dataFile);
	if (fileSize == 0)
	{
		fprintf(stderr, "File size could not be determined\n");
		return 0;
	}
	
	unsigned char * buffer = calloc(1, fileSize);
	int index = 0;

	// Read file into buffer
	readFile(dataFile, buffer, fileSize);

	// Load data for all players
	int i;
	for (i=0; i<sizeof(self->players)/sizeof(self->players[0]); i++)
	{
		Player_deserializeData( &(self->players[i]), buffer, &index );
	}

	free(buffer);

	return 1;
}

_Bool Game_serializeState(struct Game * self)
{
	char * saveFile = "assets/savegames/game1.sav";
	size_t fileSize = 3000;

	unsigned char * buffer = calloc(1, fileSize);
	int index = 0;

	// Save data from all players
	int i;
	for (i=0; i<sizeof(self->players)/sizeof(self->players[0]); i++)
	{
		Player_serializeState( &(self->players[i]), buffer, &index );
	}

	// Write buffer into file
	writeFile(saveFile, buffer, fileSize);

	free(buffer);

	return 1;
}

_Bool Game_deserializeState(struct Game * self)
{
	char * saveFile = "assets/savegames/game1.sav";
	size_t fileSize = getFileSize(saveFile);
	if (fileSize == 0)
	{
		fprintf(stderr, "Failed to load save :(\n");
		return 0;
	}
	
	unsigned char * buffer = calloc(1, fileSize);
	int index = 0;

	// Read file into buffer
	readFile(saveFile, buffer, fileSize);

	// Load data for all players
	int i;
	for (i=0; i<sizeof(self->players)/sizeof(self->players[0]); i++)
	{
		Player_deserializeState( &(self->players[i]), buffer, &index );
	}

	free(buffer);

	return 1;
}
