# Raycasting Game Engine
![sccp](https://github.com/TZITA/MAZE_PROJECT/assets/104761243/9d4b10fb-dee2-45f3-82e8-85487ac4b0a4)

This is a simple raycasting game engine written in C using SDL (Simple DirectMedia Layer) library. The engine designed to have a basic first-person perspective game similar to Wolfenstein 3D.<br>

## How it Works
The engine uses a raycasting technique to render a 3D perspective view of a game world on a 2D screen. It creates a 2D grid representation of the game world and casts rays from the player's position to determine the distance to walls and other objects in the game. Based on the distance and the player's view angle, the engine calculates the height of the walls to create a 3D illusion. The engine handles collision detection, movement, and rendering.

For an explanation about SDL library and DDA algorithm visit [my medium blog.](https://medium.com/p/e344e0f22bec)
## Features
- First-person perspective view<br>
- Collision detection with walls<br>
- Basic movement controls (forward, backward, turn left, turn right)<br>
- Simple rendering of objects and environment<br>

## Usage
- Clone the repository to your local machine.<br>
- Install the necessary dependencies (SDL2 library).<br>
- Compile the code using a C compiler. Example:  
```
gcc *.c -o maze -lm -lSDL2'
```
- Run the compiled executable to start the game. 
```
./maze
```
## File Structure
### headers directory
	1. myheader.h: Header file defining the structures and function prototypes used in the game engine.<br>

### src directory<br>
	1. main.c: Contains the main function and rendering code.<br>
	2. init.c: Contains a function to initialize SDL elements<br>
	3. move.c: Contains functions to handle player movement and close event<br>
	4. render.c: Contains functions to render game environment and events<br>
	5. cleanup.c: Contains functions to cleanup resources.<br>

## Dependencies
SDL2 library: Install the necessary SDL library to compile and run the code.

## Technical Challenge
During my first usage of SDL on my Ubuntu system, which was installed using Windows Subsystem for Linux (WSL2), I encountered a significant problem. Unfortunately, SDL was unable to render anything on my screen due to its inability to access my Windows display server. This issue was particularly challenging to resolve because WSL2 introduced an additional layer of complexity to the setup.
The error message I repeatedly received was:
```
"X Error of failed request: BadShmSeg (invalid shared segment parameter)" 
```
This error persisted for some days, leaving me frustrated and searching for a solution.<br><br> 
After thorough investigation, I discovered that the key to resolving the problem was installing an X11 display server on my system. Through my research, I decided to install Xming, an X server designed for Windows. This X server would provide the necessary functionality to establish a connection between SDL and the display server, enabling proper graphics rendering.<br><br>
With Xming successfully installed, the next step was to export my Ubuntu display to my Windows PC's IP address. I accomplished this by executing the following command in the terminal:
```
export DISPLAY=my_pc’s_IP:0
```
By setting the `DISPLAY` environment variable to my PC's IP address followed by ":0," I established the crucial connection between the Ubuntu subsystem and Xming's display server running on Windows.<br><br>
With the necessary setup in place, I eagerly tested my SDL program once again. This time, to my immense relief, it successfully rendered the graphics onto my screen without encountering any issues. Overcoming this obstacle after investing a significant amount of time and effort in troubleshooting was a truly rewarding experience.<br>
<br>
This personal encounter reinforced the importance of thoroughly understanding system configurations and dependencies when working with cross-platform development tools like SDL. It also highlighted the significance of persistent research and a determined attitude in finding solutions to complex technical challenges.<br><br>
Despite the initial hurdles I faced, SDL has proven to be an incredibly versatile and powerful graphics rendering library. Its extensive functionalities make it an excellent choice for creating captivating visual experiences. However, it is crucial to ensure proper configuration and setup, especially when working across different platforms, to fully leverage the capabilities of SDL in developing interactive applications and games.

## Limitations and Future Improvements
- The engine currently supports a fixed game world size and does not handle dynamic resizing.<br>
- The walls anf floor are not textured.<br>
- The collision detection is basic and may not handle complex scenarios.<br>
- The rendering can be improved with lighting effects and shading.<br>
- Additional features such as enemies, weapons, and levels can be added to enhance gameplay.<br><br>
Feel free to modify and improve the code according to your needs and requirements!<br>

## Credits
This code is based on the tutorial and inspiration from: [Lode Vandevenne](https://lodev.org/cgtutor/raycasting.html)

## License
This project is licensed under the MIT License.
