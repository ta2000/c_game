#ifndef INPUT_H_
#define INPUT_H_

// Forward declaration of Game
struct Game;

// Checks for input from windowing system
char getInput();

// Process input
void handleInput(struct Game * game);

#endif
