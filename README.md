# Raycasting Game Engine
This is a simple raycasting game engine written in C using SDL (Simple DirectMedia Layer) library. The engine designed to have a basic first-person perspective game similar to Wolfenstein 3D.<br \>

## How it Works
The engine uses a raycasting technique to render a 3D perspective view of a game world on a 2D screen. It creates a 2D grid representation of the game world and casts rays from the player's position to determine the distance to walls and other objects in the game. Based on the distance and the player's view angle, the engine calculates the height of the walls to create a 3D illusion. The engine handles collision detection, movement, and rendering.

## Features
First-person perspective view
Collision detection with walls
Basic movement controls (forward, backward, turn left, turn right)
Simple rendering of objects and environment

## Usage
Clone the repository to your local machine.<br \>
Install the necessary dependencies (SDL2 library).<br \>
Compile the code using a C compiler. Example, 'gcc *.c -o maze -lm -lSDL2'<br \>
Run the compiled executable to start the game. ./maze<br \>

## File Structure
headers directory<br \>
	1. myheader.h: Header file defining the structures and function prototypes used in the game engine.<br \>

src directory<br \>
	1. main.c: Contains the main function and rendering code.<br \>
	2. init.c: Contains a function to initialize SDL elements<br \>
	3. move.c: Contains functions to handle player movement and close event<br \>
	4. render.c: Contains functions to render game environment and events<br \>
	5. cleanup.c: Contains functions to cleanup resources.<br \>

## Dependencies
SDL2 library: Install the necessary SDL library to compile and run the code.

## Limitations and Future Improvements
The engine currently supports a fixed game world size and does not handle dynamic resizing.<br \>
The walls anf floor are not textured.<br \>
The collision detection is basic and may not handle complex scenarios.<br \>
The rendering can be improved with lighting effects and shading.<br \>
Additional features such as enemies, weapons, and levels can be added to enhance gameplay.<br \>
Feel free to modify and improve the code according to your needs and requirements!<br \>

## Credits
This code is based on the tutorial and inspiration from: Lode Vandevenne

## License
This project is licensed under the MIT License.
