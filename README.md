
*This project has been created as part of the 42 curriculum by msimoes*
 
## Description
So_Long is a small 2D game built using the MinilibX graphics library. The player navigates a map, collecting all items before reaching the exit. The game reads a map from a `.ber` file, validates it, and renders it in a window using XPM sprites.
 
The goal of this project is to learn the basics of 2D graphics programming, window and event management, sprite rendering, and map parsing while handling memory properly and ensuring maps are valid and beatable using flood fill.
 
## Instructions
 
### Compilation
To compile the project simply run:
```bash
make
```
To recompile everything run:
```bash
make re
```
 
Both of these will create a `so_long` executable.
 
### Usage
```bash
./so_long maps/map.ber
```
 
### Map Format
Maps must be `.ber` files and follow these rules:
- The map must be rectangular and fully surrounded by walls (`1`)
- Valid characters are: `0` (empty), `1` (wall), `P` (player), `C` (collectible), `E` (exit)
- The map must contain exactly one player (`P`) and one exit (`E`)
- The map must contain at least one collectible (`C`)
- The map must be beatable (all collectibles and the exit must be reachable)
### Controls
| Key | Action |
|-----|--------|
| `W` | Move up |
| `A` | Move left |
| `S` | Move down |
| `D` | Move right |
| `ESC` | Exit the game |
 
### Examples
Basic game launch:
```bash
./so_long maps/small_map.ber
```
```bash
./so_long maps/big_map.ber
```
 
### Cleanup
Remove object files:
```bash
make clean
```
Remove object files and executable:
```bash
make fclean
```
 
## Resources
- [MinilibX documentation](https://harm-smits.github.io/42docs/libs/minilibx)
- [Flood Fill algorithm - Wikipedia](https://en.wikipedia.org/wiki/Flood_fill)
- [XPM format - Wikipedia](https://en.wikipedia.org/wiki/X_PixMap)
### AI usage
No AI was used to write the code of this project. AI was used to create a draft of this README.
