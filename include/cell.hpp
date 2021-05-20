#ifndef CELL_M1ST
#define CELL_M1ST

#include "../include/SFML/Graphics.hpp"
class Cell {

    int row, col;

    bool visited = false;
    bool walls[4];
    bool special[3] = {false, false, false};

    enum dir {TOP, RIGHT, BOTTOM, LEFT};

    void shuffle(std::vector<int> &);
    public:

        Cell(int x, int y); // Complete

        void setVisited(bool); // Complete 
        // int getPref();
        void show(sf::RenderWindow &); // WIP
        void removeWalls(Cell &); // Complete

        void done();
        void isStart();
        void isFinish();
        void setWalls(); // Complete
        bool isVisited(); // Complete

        int getRow(); // Complete
        int getCol(); // Complete
};

#endif //CELL_M1ST