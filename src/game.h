#ifndef GAME_H_
#define GAME_H_

struct Game
{
    _Bool running;
    void (*run)();
    struct Player players[1];
};

// Create all players
void Game_create(struct Game * self);

// Begin game loop
void Game_run(struct Game * self);


#endif
