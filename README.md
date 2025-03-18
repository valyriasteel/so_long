# so_long
![so_long](https://img.shields.io/badge/so_long-2D%20Game%20Project-blue.svg)

## 📌 Project Description
`so_long` is a simple 2D game project where players navigate through a map, collect items, and reach an exit. The game is built using the MinilibX graphics library and provides an engaging gaming experience through simple mechanics.

## 📂 Features
- Simple and engaging 2D game with keyboard controls
- Custom maps created using configuration files
- Map validation to ensure playability
- Collectible items and exit point mechanics
- Movement counter to track player progress
- Error handling for various game scenarios
- Built with MinilibX graphics library

## ⚙️ Installation
### Prerequisites
- MinilibX library
- GCC compiler
- Make

### Compilation
Compile the project using the `Makefile`:
```sh
make
```

## 🚀 Usage
Run the game with a map file as an argument:
```sh
./so_long maps/map.ber
```

## 🗺️ Map Configuration
Maps are defined in `.ber` files with the following elements:
- `1`: Wall
- `0`: Empty space
- `P`: Player starting position
- `E`: Exit
- `C`: Collectible item

### Example Map:
```
11111111111111111111111111
100C1000000C0000C10C000001
10010000000000001000000C01
100000111C000001C000010001
10P001EC0000C00000C0000001
11111111111111111111111111
```

### Map Requirements:
- Must be surrounded by walls (1)
- Must have exactly one player starting position (P)
- Must have exactly one exit (E)
- Must have at least one collectible (C)
- Must be rectangular
- Must have a valid path to collect all items and reach the exit

## 🕹️ Controls
- `W` or `↑`: Move up
- `A` or `←`: Move left
- `S` or `↓`: Move down
- `D` or `→`: Move right
- `C`: Show collisions
- `ESC`: Close the game

## 🚫 Error Handling
The program handles various error scenarios including:
- Invalid map format
- Missing map elements
- Inaccessible collectibles or exit
- Memory allocation failures
- File reading errors

## 📜 License
This project is licensed under the **[MIT License](LICENSE)**.

## 📧 Contact
For any questions or feedback, feel free to reach out via GitHub!
