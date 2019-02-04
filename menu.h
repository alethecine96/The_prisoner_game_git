//
// Created by francesco on 29/07/18.
//

#ifndef PROJECT_MENU_H
#define PROJECT_MENU_H

#pragma once
#include "SFML/Graphics.hpp"
#include "Player.h"

#define MAX_NUMBER_OF_ITEMS 3

class Menu {
public:
    Menu(float width, float height);
    ~Menu();
    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem() { return selectedItemIndex; }

private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];
    sf::Texture background;
    sf::Sprite backgroundS;
};


#endif //PROJECT_MENU_H
