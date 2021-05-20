#ifndef GRID_M1ST
#define GRID_M1ST

#include "cell.hpp"
#include <vector>
#include <stack>
#include <thread>
#include <chrono>
#include "../include/SFML/Graphics.hpp"

class Grid {

    sf::RenderWindow *win; // Pointer to window
    int width; // Width of each cell
    int height; // Height of each cell

    std::vector<Cell> cells; // Array of cells with width and height
    std::stack<Cell *> backtrack; // Stack of cells for recursive backtracking
    Cell *current; // Cell currently being worked with from cells

    void createCells(); // Complete
    int index(int i, int j); // Complete
    std::vector<Cell *> getAvailableNeighbors();
    Cell *findNext(); // Complete
    void show(); // Complete

    public:

        Grid(int _height, int _width, sf::RenderWindow& _win); // Complete
        void generateMaze(); // Complete
};

#endif //GRID_M1ST