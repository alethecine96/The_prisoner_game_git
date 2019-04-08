//
// Created by francesco on 06/01/18.
//
#include "menu.h"
#include <iostream>


Menu::Menu(float width, float height)
{
    if (!font.loadFromFile("arial.ttf"))
    {
        std::cout << "Font Error" << std::endl;
    }
    if (!background.loadFromFile("background1.jpg")){
        std::cout << "Texture Error" << std::endl;
    }
    backgroundS.setTexture(background);
    backgroundS.setPosition(origin,origin);

    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Green);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
    menu[0].setScale(2.0f, 2.0f);

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Options");
    menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));
    menu[1].setScale(2.0f, 2.0f);

    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Exit");
    menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));
    menu[2].setScale(2.0f, 2.0f);

    selectedItemIndex = 0;
}

Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window)
{
    window.draw(backgroundS);
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        window.draw(menu[i]);
    }
}

void Menu::MoveUp()
{
    if (selectedItemIndex - 1 >= 0)
    {
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setColor(sf::Color::Green);
    }
}

void Menu::MoveDown()
{
    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
    {
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setColor(sf::Color::Green);
    }
}