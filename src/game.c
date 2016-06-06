#include <stdio.h>
#include <unistd.h>
#include <malloc.h>

#include "gameobject.h"
#include "unit.h"
#include "game.h"

void Game_init(struct Game * self)
{
    self->running = 1;

    // Init all units in pool
    int i;
    for (i = 0; i < sizeof(self->units)/sizeof(self->units[0]); i++)
    {
        Unit_init(&self->units[i],5,5,100,0,180);
    }
}

// Game loop
void Game_run(struct Game * self)
{
    int i;
    while (self->running)
    {
        // Update all units
        for (i = 0; i < sizeof(self->units)/sizeof(self->units[0]); i++)
        {
            Unit_update(&self->units[i]);
        }
        // Newline before next frame
        printf("\n");
        sleep(1);
    }
}
