
# Project Mundo

## Description
The "Mundo" project is an interactive game that simulates an environment where objects like trees, food, sun, moon, and clouds are generated and drawn on a board. The game utilizes the GLM library for matrix manipulation and shaders for graphical rendering.

## Project Structure
- `Mundo.cpp`: Implementation of the `Mundo` class, which manages the creation and drawing of objects in the environment.
- `Mundo.h`: Header for the `Mundo` class.
- `Shader.hh`: Implementation of shaders used in the project.
- `stb_image.h`: Library for image loading.

## Features
- Creation of a dynamic scenario with objects appearing at random positions.
- Drawing of objects on the screen with support for different cameras.
- Clearing of objects from the world for reinitialization.

## Compilation
To compile the project, use the following command:

```bash
g++ -o mundo Mundo.cpp -lGL -lGLU -lglut
```

## Usage
After compiling, run the program with the following command:

```bash
./mundo
```

```bash
./mundo
```

## Dependencies
- GLM
- OpenGL
- GLUT

## Contribution
Contributions are welcome! Feel free to open a pull request or report issues.

## License
This project is licensed under the MIT License - see the LICENSE file for more details.

## Screenshot of the 3d models in action
![image](https://github.com/user-attachments/assets/df7b5aec-221c-4fa1-a6a4-ca11af2039ca)
