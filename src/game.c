#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <malloc.h>

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
	
	if (file == NULL)
	{
		printf("Could not find file.\n");
		fclose(file);
		return 0;
	}

	size_t bytes_read;
	bytes_read = fread(self, sizeof(*self), 1, file);

	fclose(file);

	return 1;
}
