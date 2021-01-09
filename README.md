# Conways-Game-of-Life
### Developed in Fall 2019
C++ implementation of Conway's Game of Life. User can run the game in two ways:
- Interactive Mode: User adds all cells manually and progresses as fast/slow as they please
```bash
./playlife
```
- Input Mode: Program reads in a text file of cells to automatically make "alive" before progressing the game infinitely
```bash
./playlife glider.text
```

### Commands
|Command|Action|
|-------|------|
|a|Add Cell at Coordinate
|r| Remove Cell at Coordinate|
|n| Advance to the next Generation|
|p| Progress the game infinitely|
|q| Quit|
