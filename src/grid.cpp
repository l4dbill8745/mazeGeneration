/* This program is free software. It comes without any warranty, to
     * the extent permitted by applicable law. You can redistribute it
     * and/or modify it under the terms of the Do What The Fuck You Want
     * To Public License, Version 2, as published by Sam Hocevar. See
     * http://www.wtfpl.net/ for more details. */

#include "../include/grid.hpp"
#include "../include/cell.hpp"

Grid::Grid(int _height, int _width, sf::RenderWindow& _win){
    height = _height;
    width = _width;
    win = &_win;
    createCells();
    srand(time(0));
    current = &cells[rand() % cells.size()];
}

void Grid::createCells() {
    for(int j = 0; j < width; j++){
        for(int i = 0; i < height; i++){
            cells.push_back(Cell(i, j));
        }
    }
}

int Grid::index(int i, int j){
    if (i < 0 || j < 0 || i >= width || j >= height ) return -1;
    return i + j * height;
}

std::vector<Cell *> Grid::getAvailableNeighbors(){
    std::vector<Cell *> neighbors;
    int cRow = current->getRow();
    int cCol = current->getCol();

    int neighborIdx[4] = {
        index(cRow  ,cCol-1),
        index(cRow+1,cCol  ),
        index(cRow  ,cCol+1),
        index(cRow-1,cCol  ),
    };

    for (int i : neighborIdx){
        if (i != -1 && !cells[i].isVisited())
            neighbors.push_back(&cells[i]);
    }
    return neighbors;
}

Cell *Grid::findNext(){
    std::vector<Cell *> availableNeighbors = getAvailableNeighbors();
    // srand(time(0));
    if (availableNeighbors.size() > 0)
        return availableNeighbors[rand() % availableNeighbors.size()];
    return NULL;
}

void Grid::show(){
    for (int i = 0; i < cells.size(); i++){
        cells[i].show(*win);
    }
}

void Grid::generateMaze(){
    current->setVisited(true);
    Cell *next = findNext();
    if (index(current->getRow(),current->getCol()) == cells.size()-1) current->isFinish();
    if (next != NULL){
        next->setVisited(true);
        backtrack.push(current);
        current->removeWalls(*next);
        current = next;
    }
    else if (backtrack.size() > 0){
        current->done();
        current = backtrack.top();
        backtrack.pop();
    }
    else if (backtrack.size() == 0){
        current->isStart();
    }
    // std::this_thread::sleep_for(std::chrono::milliseconds(75));
    show();
}
