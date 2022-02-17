#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    //--------------------INTERFACE--------------------//
    //(BUTTONS AND MAYBE STH ELSE)
    sf::RectangleShape file_button(sf::Vector2f(50, 30));
    file_button.setFillColor(sf::Color(140, 140, 140));   //158, 158, 158
    file_button.setPosition(sf::Vector2f(0, 0));

    sf::RectangleShape edit_button(sf::Vector2f(50, 30));
    edit_button.setFillColor(sf::Color(140, 140, 140));
    edit_button.setPosition(sf::Vector2f(52, 0));

    sf::RectangleShape brush_button(sf::Vector2f(80, 160));
    brush_button.setFillColor(sf::Color(140, 140, 140));
    brush_button.setPosition(sf::Vector2f(50, 40));
    sf::Vector2i mouse = sf::Mouse::getPosition(window);            //vector input mouse' position in window


    window.clear(sf::Color(111, 111, 111));
    //--------------------ACTING--------------------------//
    //it doesn't work, need to fix it
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        if(file_button.getGlobalBounds().contains(mouse.x, mouse.y))
        {
            std::cout << "AAAAAAAAAAAAAAAa\n";
        }
    //--------------------STRINGS-------------------------//
    sf::Font font;
    std::string path("..\\fonts\\ArialRegular.ttf");
    font.loadFromFile(path);

    sf::Text file_text;
    file_text.setFont(font);
    file_text.setCharacterSize(15);
    file_text.setString("File");
    file_text.setPosition(sf::Vector2f(13, 7));

    sf::Text edit_text;
    edit_text.setFont(font);
    edit_text.setCharacterSize(15);
    edit_text.setString("Edit");
    edit_text.setPosition(sf::Vector2f(65, 7));
    //--------------------PICTURES---------------------//
    //(FOR BRUSH, ERASER, COLORS, ETC.)

//pattern
//    sf::Texture tex;
//    sf::Sprite test_image;
//    tex.loadFromFile(/*path*/);
//    test_image.setTexture(tex);
//    test_image.setPosition(0, 500);

    //--------------------DRAWING----------------------//
    window.draw(file_button);
    window.draw(edit_button);
    window.draw(brush_button);
    window.draw(file_text);
    window.draw(edit_text);
//    window.draw(test_image);
    window.display();

    while (window.isOpen()) // run the program as long as the window is open
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
    return 0;
}