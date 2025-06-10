# Tic Tac Toe Framework

A modular C++ framework for building and experimenting with Tic Tac Toe implementations.

## Overview

This repository provides a flexible Tic Tac Toe development package rather than a standalone game. It's designed for developers to experiment with game logic, AI implementations, and custom player modules.

## Framework Components

- Core game engine with standard 3x3 Tic Tac Toe rules
- Modular architecture for extending functionality:
    - Standard terminal player module (reference implementation)
    - AI Player module using [NeuralNetwork](https://github.com/dredstone1/NeuralNetwork)
- Cross-platform compatibility (Windows, macOS, Linux)
- Extensible interface supporting custom clients and players

## Development Requirements

- C++17 compatible compiler (GCC 7+, Clang 5+, MSVC 2019+)
- CMake 3.28 or higher
- Make (for Unix-based systems) or equivalent build tool

## Getting Started

```bash
# Clone the repository
git clone https://github.com/dredstone1/tic_tac_toe.git
cd tic_tac_toe

# Create build directory
mkdir build && cd build

# Configure and build
cmake ..
make

# Run the sample implementation
./tic_tac_toe
```

## Package Structure

```
.
├── CMakeLists.txt          # Main CMake configuration
├── library/                # Core modules
│   ├── AiPlayer/           # AI player module (extensible)
│   ├── TicTacToe/          # Game engine package
│   └── StandartPlayer/     # Standard CLI player implementation
├── ModelData/              # AI model configuration
│   ├── database.txt        # Predefined game states database
│   └── config.json         # Neural network configuration
├── main.cpp                # Example implementation
└── README.md               # This file
```

## Core Game Logic

The TicTacToe module implements the standard rules:
1. Game is played on a 3x3 grid
2. Players alternate placing X or O in empty cells
3. First player to align 3 of their marks (horizontally, vertically, or diagonally) wins
4. If all cells are filled with no winner, the game is a draw

## Experimenting with AI

The framework includes an AI module for experimentation and learning:

- Built on the [NeuralNetwork](https://github.com/dredstone1/NeuralNetwork) library
- Uses a Python-generated database of predefined game states
- Provides a testing ground for neural network decision-making in games
- Offers a reference implementation that developers can modify or extend

The ModelData directory contains the configuration and database files needed for the AI module, though the neural network model itself is not included in the repository.

## Creating Custom Modules

Developers can create their own player modules by:
1. Implementing the player interface
2. Registering the module with the core game engine
3. Building custom decision-making logic or user interfaces

See the StandartPlayer implementation for a reference example.

## To Do

* Remote Network Player (client-server architecture)
* UI Interface Player
* Better player handling mechanism
* Better error handling

## License

This project is licensed under the MIT License - see the LICENSE file for details.

---

⭐ If you find this project interesting, consider giving it a star!
