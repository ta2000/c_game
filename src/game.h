#ifndef GAME_H_
#define GAME_H_

enum IndentationLevel
{
	NONE,
	FACTION,
	FACTORY,
	PRODUCTS,
	UNIT
};

struct Game
{
    _Bool running;
    struct Player players[1];
	int nextAvailablePlayer;
	enum IndentationLevel level;
};

// Create all players
void Game_create(struct Game * self);

// Begin game loop
void Game_run(struct Game * self);

// Read data file line by line, pass to parseLine
_Bool Game_readData(struct Game * self);

// Parse key/value from line, pass to loadData
void Game_parseLine(struct Game * self, char * line);

// Set values of players using key/value
void Game_loadData(struct Game * self, char * key, char * value);

#endif
