#ifndef GAME_H_
#define GAME_H_

struct Game
{
    _Bool running;
    void (*run)();
    struct Player players[1];
};

void Game_init(struct Game * self);

void Game_run(struct Game * self);


#endif
