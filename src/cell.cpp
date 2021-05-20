/* This program is free software. It comes without any warranty, to
     * the extent permitted by applicable law. You can redistribute it
     * and/or modify it under the terms of the Do What The Fuck You Want
     * To Public License, Version 2, as published by Sam Hocevar. See
     * http://www.wtfpl.net/ for more details. */

#include "../include/cell.hpp"
#include <cstdlib>
#include <iostream>

Cell::Cell(int i, int j){
    row = i;
    col = j;
    visited = false;
    setWalls();
}

void Cell::setWalls(){
    for (int i = 0; i < 4; i++) walls[i] = true;
}

void Cell::isFinish(){special[0] = true;}
void Cell::isStart(){special[1] = true;}
void Cell::done(){special[2] = true;}
void Cell::setVisited(bool b){ visited = b; }
bool Cell::isVisited(){ return visited; }

int Cell::getCol(){ return col; }
int Cell::getRow(){ return row; }

void Cell::removeWalls(Cell &next){
    int x = col - next.col;
    int y = row - next.row;

    switch(x){
        case  1: walls[LEFT] = false; next.walls[RIGHT] = false; break;
        case -1: walls[RIGHT] = false; next.walls[LEFT] = false; break;
    }
    switch(y){
        case  1: walls[TOP] = false; next.walls[BOTTOM] = false; break;
        case -1: walls[BOTTOM] = false; next.walls[TOP] = false; break;
    }
}

void Cell::show(sf::RenderWindow& _win){

    int x = col * 20;
    int y = row * 20;

    sf::RectangleShape info(sf::Vector2f(20.f,20.f));
    info.setPosition(x,y);

    std::vector<sf::Vertex> top = {
        sf::Vertex(sf::Vector2f(x,y), sf::Color::Black),
        sf::Vertex(sf::Vector2f(x+20,y), sf::Color::Black)
    };
    std::vector<sf::Vertex> right = {
        sf::Vertex(sf::Vector2f(x+20,y), sf::Color::Black),
        sf::Vertex(sf::Vector2f(x+20,y+20), sf::Color::Black)
    };
    std::vector<sf::Vertex> bottom = {
        sf::Vertex(sf::Vector2f(x+20,y+20), sf::Color::Black),
        sf::Vertex(sf::Vector2f(x,y+20), sf::Color::Black)
    };
    std::vector<sf::Vertex> left = {
        sf::Vertex(sf::Vector2f(x, y+20), sf::Color::Black),
        sf::Vertex(sf::Vector2f(x, y), sf::Color::Black)
    };

    if (special[0]){
        info.setFillColor(sf::Color(255,0,0,100));
        _win.draw(info);
    } else if (special[1]){
        info.setFillColor(sf::Color(0,255,100,100));
        _win.draw(info);
    } else if (special[2]){
        info.setFillColor(sf::Color(255,255,255,100));
        _win.draw(info);
    } else if (visited){
        info.setFillColor(sf::Color(255,0,255,100));
        _win.draw(info);
    }
    if (walls[TOP]){
        _win.draw(&top[0], top.size(), sf::Lines);
    }
    if (walls[RIGHT]){
        _win.draw(&right[0], right.size(), sf::Lines);
    }
    if (walls[BOTTOM]){
        _win.draw(&bottom[0], bottom.size(), sf::Lines);
    }
    if (walls[LEFT]){
        _win.draw(&left[0], left.size(), sf::Lines);
    }
}
