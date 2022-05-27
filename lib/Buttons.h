#ifndef MAIN_CPP_BUTTONS_H
#define MAIN_CPP_BUTTONS_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

/// The class Buttons is class type of sf::RectangleShape.
///
/// It is has a public method *getButton, which is the constructor of the class.

class Buttons
{
public:
    static sf::RectangleShape *getButton(float width, float height, float x, float y, sf::Color color);
};


#endif
