# 42-Cub3d

## Description
42-Cub3d is a 3D graphics project that implements a simple raycasting engine, similar to the classic game Wolfenstein 3D. This project is part of the 42 school curriculum and focuses on creating a basic 3D maze-like environment.

## Features
- 3D rendering using raycasting technique
- Textured walls
- Player movement and rotation
- Map parsing from a custom file format
- Collision detection

## Requirements
- MinilibX library
- C compiler (gcc recommended)
- Make

## Installation
1. Clone the repository:

```bash
git clone https://github.com/yourusername/42-Cub3d.git
```

2. Navigate to the project directory:

```bash
cd Cub3d
```

3. Compile the project:

```bash
make
```

## Usage
Run the executable with a map file as an argument:

```bash
./cub3d maps/map.cub
```
same for the bonus

```bash
./cub3d_bonus maps/map_bonus.cub
```

## Screenshots



## Map Format
The game uses a custom map format with the following elements:
- NO, SO, WE, EA: Paths to wall textures
- F, C: Floor and ceiling colors (RGB format)
- Map layout using characters:
  - 0: Empty space
  - 1: Wall
  - N/S/E/W: Player starting position and orientation

## Controls
- W/A/S/D: Move the player
- Left/Right arrow keys: Rotate the camera

## Author

Ait Omar Abdeljalil (aait-oma@student.1337.ma)

## Acknowledgements
This project is part of the 42 school curriculum.
