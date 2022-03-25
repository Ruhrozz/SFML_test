#include "Buttons.h"


sf::RectangleShape *Buttons::getButton(float width, float height, float x, float y, sf::Color color) {
    auto button = new sf::RectangleShape(sf::Vector2f(width, height));
    button->setFillColor(color);   //158, 158, 158
    button->setPosition(sf::Vector2f(x, y));
    return button;
}

