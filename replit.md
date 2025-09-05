# Overview

This project implements three graph search algorithms to solve pathfinding problems in a "Cretan labyrinth" scenario. The system provides an interactive menu interface allowing users to choose between different search strategies: Depth-First Search (DFS), A* algorithm, and Uniform Cost Search (Dijkstra) with thread limitations. The project is designed as an educational tool to demonstrate different graph traversal techniques and their trade-offs in finding optimal paths.

# User Preferences

Preferred communication style: Simple, everyday language.

# System Architecture

## Core Components

**Modular Algorithm Design**: The system is structured with separate modules for each search algorithm (DFS, A*, Dijkstra), promoting code reusability and maintainability. Each algorithm is implemented in its own header and source file pair, allowing for independent development and testing.

**Graph Representation**: The system uses a graph data structure to represent the labyrinth, with nodes representing points and edges representing possible paths with associated costs. The graph supports directed connections as specified in the input format.

**Parser System**: A dedicated parser module handles input file processing, converting the Prolog-style syntax into internal graph representations. This design separates data input concerns from algorithm logic.

**Interactive Menu Interface**: The main application provides a console-based menu system that allows users to select different algorithms and view results, making the system accessible for educational purposes.

**Heuristic Support**: The A* implementation incorporates heuristic functions (h-values) for more efficient pathfinding, demonstrating the difference between informed and uninformed search strategies.

## Design Patterns

**Strategy Pattern**: Different search algorithms are implemented as interchangeable strategies, allowing the system to switch between DFS, A*, and Dijkstra based on user selection.

**Single Responsibility Principle**: Each module has a clear, focused responsibility - graph management, parsing, or implementing a specific search algorithm.

**Data-Driven Configuration**: The system reads graph configurations from external text files, making it easy to test different scenarios without code modifications.

# External Dependencies

**C++ Standard Library**: The project relies on standard C++11 features and libraries for data structures, I/O operations, and memory management.

**File System Access**: The system reads graph definitions from text files in the input directory, requiring standard file I/O capabilities.

**Compiler Requirements**: Requires GCC, Clang, or compatible C++ compiler supporting C++11 standards for compilation across Linux, macOS, and Windows platforms.

**No External Libraries**: The project is designed to be self-contained without requiring additional third-party libraries or frameworks, making it easy to compile and run in various environments.