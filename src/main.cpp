#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

#include "../include/cell.hpp"
#include "../include/grid.hpp"

int main(int argc, char ** argv){
    sf::RenderWindow window(sf::VideoMode(400, 400), "Maze Generator!");
    int scl[2] = {(int)(window.getSize().x)/20, (int)(window.getSize().y)/20};
    Grid grid(scl[0], scl[1], window);

    while (window.isOpen()){
    
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
                std::cout << "Process Exited Normally." << std::endl;
            }
        }
    
        window.clear();
        grid.generateMaze();
        window.display();
    }
    return 0;
}