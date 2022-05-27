#ifndef SFML_PROJECT_TEXT_H
#define SFML_PROJECT_TEXT_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

/**
 * The class Text is class type of sf::Text, it is has a public method *getText, which is the constructor of the class.
 */


class Text
{
public:
    static sf::Text *getText(const sf::Font& font, const sf::String &str, float x, float y, unsigned int CharacterSize);


};


#endif //SFML_PROJECT_TEXT_H
