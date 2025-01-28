# cub3D

cub3D is my first RayCaster project created using miniLibX. Inspired by the classic **Wolfenstein 3D**, this project explores the principles of ray-casting to create a dynamic first-person view inside a maze.

---

## Features

### Mandatory
- Render a "realistic" 3D graphical representation of a maze from a first-person perspective.
- Navigation using keyboard controls:
  - **Arrow keys**: Look left and right.
  - **W, A, S, D**: Move around the maze.
  - **ESC**: Exit the program.
  - **Red cross**: Close the window gracefully.
- Display walls with textures that vary based on their orientation (N/S/E/W).
- Customizable floor and ceiling colors.
- Parse `.cub` configuration files for map layout and textures.

### Bonus (if applicable)
- Wall collisions.
- Minimap system.
- Doors that open and close.
- Animated sprites.
- Mouse-controlled view rotation.
- Additional HUD elements like health bars, shadows, and weapons.

---

## How to Use

   Clone this repository:
   bash
   git clone <repository_url>
   cd cub3D
   make
   ./cub3D maps/test.cub (or any other map path)

### Requirements

    Language: C
    Libraries: miniLibX, math library (-lm)
    Compilation: make with rules for all, clean, fclean, re, and bonus.
