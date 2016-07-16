#ifndef GAME_H_
#define GAME_H_

struct Game
{
    _Bool running;
    struct Player players[1];
};

// Create all players
void Game_init(struct Game * self);

// Begin game loop
void Game_run(struct Game * self);

// Save game data
_Bool Game_serializeData(struct Game * self);
// Load game data
_Bool Game_deserializeData(struct Game * self);

// Save game state to file
_Bool Game_serializeState(struct Game * self);
// Load game state from file
_Bool Game_deserializeState(struct Game * self);

#endif
