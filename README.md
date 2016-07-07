#c game [![Build Status](https://drone.carpoolme.net/api/badges/ta2000/c_game/status.svg)](https://drone.carpoolme.net/ta2000/c_game)

An RTS game written in C. I plan to use OpenGL or Vulkan for graphics once most of the game logic is completed. The .json file in /assets/data is not used, just a text representation of the data.dat file.

Developing
---

```bash
git clone https://github.com/ta2000/c_game.git
cd c_game
autoreconf --install
./configure
make -j
```
