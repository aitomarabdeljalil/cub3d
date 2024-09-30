# Cub3d

## Description
Cub3d is a 3D graphics project that implements a simple raycasting engine, similar to the classic game Wolfenstein 3D. This project is part of the 42 school curriculum and focuses on creating a basic 3D maze-like environment.

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
git clone https://github.com/aitomarabdeljalil/cub3d.git
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
<img width="1202" alt="Screen Shot 2024-09-30 at 11 52 27 AM" src="https://github.com/user-attachments/assets/5d2b34a8-17f8-4330-a512-c60f20e6b2fa">
<img width="1201" alt="Screen Shot 2024-09-30 at 11 53 42 AM" src="https://github.com/user-attachments/assets/ccfb55b6-1177-4a08-8433-1a5593709b8f">



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
