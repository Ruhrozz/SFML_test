#include "Text.h"

///
/// The function create a text line.
///
/// @param font The font applied to the text
/// @param str Tрe string with the text to be output
/// @param x The coordinate of the upper left corner on the x axis
/// @param y The coordinate of the upper left corner on the y axis
/// @param CharacterSize The font size, default is 15
///
/// @return The function returns an object of type sf::Text
///


sf::Text *Text::getText(const sf::Font& font, const sf::String &str, float x, float y, unsigned int CharacterSize = 15)
{
    auto text = new sf::Text;
    text->setFont(font);
    text->setCharacterSize(CharacterSize);
    text->setString(str);
    text->setPosition(sf::Vector2f(x, y));
    return text;
}