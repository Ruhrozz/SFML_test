#ifndef MAIN_CPP_BUTTONS_H
#define MAIN_CPP_BUTTONS_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


class Buttons
{
public:
    static sf::RectangleShape *getButton(float width, float height, float x, float y, sf::Color color);
};


#endif
