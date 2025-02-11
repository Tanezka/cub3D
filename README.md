# cub3D - First-Person Raycaster

Welcome to **cub3D**, a **Wolfenstein 3D-inspired** project where we implemented a **raycasting** engine to visualize a 3D maze from a first-person perspective using **MiniLibX**.

## 📌 Features
- 🔺 **Raycasting**: Simulating a 3D environment with a 2D map.
- 🎨 **Textured walls**: Different textures for different orientations.
- 🏃 **Smooth player movement**: Move with `W, A, S, D` and rotate with arrow keys.

---
## 📂 Project Structure
```plaintext
├── src/          # Source files
├── includes/     # Header files
├── maps/         # Game maps (.cub files)
├── assets/       # Textures and sprites
├── Makefile      # Compilation script
└── README.md     # Project documentation
```
---
## ⚡ Installation & Execution
1. Clone the repository:
   ```sh
   git clone https://github.com/yourusername/cub3D.git
   cd cub3D
   ```
2. Compile the project:
   ```sh
   make
   ```
3. Run the game with a map:
   ```sh
   ./cub3D maps/example_map.cub
   ```
---
## 📜 Game Mechanics
1. **Movement**
   - Move: `W, A, S, D`
   - Rotate view: `←, →`
   - Exit: `ESC`
2. **Rendering**
   - Raycasting to simulate depth perception.
   - Different textures for walls depending on direction.
   - Floor and ceiling colors customizable.
3. **Map Requirements**
   - Walls (`1`), empty space (`0`), and player spawn (`N, S, E, W`).
   - Must be enclosed by walls.
   - Configurable textures for each wall direction.

---
## 📢 Contributions
Contributions are welcome! Feel free to submit issues or pull requests.

---
## 📄 License
This project is licensed under the **MIT License**.

🏆 *Enjoy coding and creating your own 3D game world!*
