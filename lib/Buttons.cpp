#include "Buttons.h"

///
/// The function create a rectangle shape for a button.
///
/// @param width The width of rectangle shape.
/// @param height The height of rectangle shape.
/// @param x The coordinate of the upper left corner on the x axis
/// @param y The coordinate of the upper left corner on the y axis
/// @param color The color of rectangle shape, it's regulated by the values of the rgb model.
///
/// @return The function returns an object of type sf::RectangleShape
///


sf::RectangleShape *Buttons::getButton(float width, float height, float x, float y, sf::Color color) {
    auto button = new sf::RectangleShape(sf::Vector2f(width, height));
    button->setFillColor(color);   //158, 158, 158
    button->setPosition(sf::Vector2f(x, y));
    return button;
}

