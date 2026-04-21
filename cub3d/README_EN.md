*This project has been created as part of the 42 curriculum by achauvie and tjourdai.*

# cub3d
![42 Cursus](https://img.shields.io/badge/42-Cursus-blue?style=for-the-badge)
![Projects](https://img.shields.io/badge/Projects-Common_Core-success?style=for-the-badge)
<!-- [![Score](https://img.shields.io/badge/score-125%20%2F%20100-success?style=for-the-badge)](https://github.com/AlexisParder/42_Cursus/tree/main/cub3d)<br> -->
[🇫🇷 French](./README.md)
- [cub3d](#cub3d)
	- [Description](#description)
	- [Instructions](#instructions)
		- [Mandatory](#mandatory)
		- [Bonus](#bonus)
	- [Bonus](#bonus-1)
	- [Controls](#controls)
		- [Mandatory](#mandatory-1)
		- [Bonus](#bonus-2)
	- [Maps](#maps)
	- [Example of .cub file](#example-of-cub-file)
	- [Use of AI](#use-of-ai)
	- [Resources](#resources)

## Description
A graphics programming project inspired by early raycasting engines like Wolfenstein 3D. The objective is to build a pseudo-3D renderer using a 2D map and raycasting techniques to simulate a first-person perspective. The implementation involves parsing map files, handling player movement and camera rotation, performing real-time ray calculations, and rendering textured walls with correct depth and perspective. 

Additional challenges include managing sprites, collision detection, and optimizing performance for smooth rendering. This project develops strong skills in computer graphics fundamentals, trigonometry, real-time rendering, low-level optimization, and structured game engine design within a constrained C environment.

## Instructions
### Mandatory
- Use the `make` command to compile the program.
- Use the `./cub3D <path/map_file>.cub` command to start game.
### Bonus
- Use the `make bonus` command to compile the program with bonus.
- Use the `./cub3D <path/map_file>.cub` command to start game.

## Bonus
- [ ] Wall collisions.
- [ ] A minimap system.
- [ ] Doors which can open and close.
- [ ] Animated sprites.
- [ ] Rotate the point of view with the mouse.

## Controls
### Mandatory
| Key                   | Action Description           |
|-----------------------|------------------------------|
| **W**                 | Move up                      |
| **A**                 | Move left                    |
| **S**                 | Move down                    |
| **D**                 | Move right                   |
| **← (Left)**          | Turn camera left             |
| **→ (Right)**         | Turn camera right            |
| **ESCAPE**            | Quit game                    |
### Bonus
| Key                   | Action Description           |
|-----------------------|------------------------------|
| **MOUSE**             | Turn camera                  |

## Maps
The map must follow certain rules:
- The map must be in the `.cub` format.
- The map can be composed of only these 6 characters:
  - **0**: empty space
  - **1**: wall
  - **N**: player starting position, facing North
  - **S**: player starting position, facing South
  - **E**: player starting position, facing East
  - **W**: player starting position, facing West
	<!-- - For the bonus, you can add
		- **D**: door -->
- To be valid, a map must contain 1 player starting position.
- The map must be enclosed/surrounded by walls.

## Example of .cub file
```
NO ./textures/wall.png
SO ./textures/wall.jpg
WE ./textures/wall.jpeg
EA ./textures/wall.bmp

F 220,100,0
C 225,30,0

           1111111111111111111111111
           1000000000110000000000001
           1011000001110000000000001
           1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```
- **NO**: texture (format: `png`, `jpg`, `jpeg` or `bmp`) to apply to the north face of the cubes.
- **SO**: texture (format: `png`, `jpg`, `jpeg` or `bmp`) to apply to the south face of the cubes.
- **WE**: texture (format: `png`, `jpg`, `jpeg` or `bmp`) to apply to the west face of the cubes.
- **EA**: texture (format: `png`, `jpg`, `jpeg` or `bmp`) to apply to the east face of the cubes.
- **F**: floor color (format: `r`,`g`,`b`).
- **C**: ceiling color (format: `r`,`g`,`b`).
- **Note**: the parameters above can be specified in any order. However, the map must always be placed last.

## Use of AI
Artificial intelligence was used as a support to understand and organize the key concepts of the project.

## Resources
- [C math (math.h) Library](https://www.w3schools.com/c/c_ref_math.php)
- [MacroLibX](https://macrolibx.kbz8.me/guides/getting_started/)
- [(French) Mathematical Concepts of the Cub3D Project](https://docs.google.com/document/d/1tdNYHg3Mfqf8dr8W6Ajs3seUugwtmaQizZ7BzimkXog/edit)