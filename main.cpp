#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>


sf::RectangleShape *getButton(float width, float height, float x, float y) {
    auto file_button = new sf::RectangleShape(sf::Vector2f(width, height));
    file_button->setFillColor(sf::Color(140, 140, 140));   //158, 158, 158
    file_button->setPosition(sf::Vector2f(x, y));
    return file_button;
}


int main()
{
    bool isFullscreen = false;


    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");


    //TODO: create shapes and pictures array
    auto file_button = getButton(50, 30, 0, 0);
    auto edit_button = getButton(50, 30, 52, 0);
    auto brush_button = getButton(300, 300, 50, 40);


    //--------------------STRINGS-------------------------//
    sf::Font font;
    std::string path("..\\fonts\\ArialRegular.ttf");
    font.loadFromFile(path);


    // TODO: !squeeze to functions!
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


    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::F5))
        {
            window.close();
            if(!isFullscreen)
                window.create(sf::VideoMode::getDesktopMode(), "My window", sf::Style::Fullscreen);
            else
                window.create(sf::VideoMode(800, 600), "My window");
            isFullscreen = !isFullscreen;
            while(sf::Keyboard::isKeyPressed(sf::Keyboard::F5))
                ;
        }

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i mouse = sf::Mouse::getPosition(window);
            if (file_button->getGlobalBounds().contains(mouse.x, mouse.y))
            {
                std::cout << "AAAAAAAAAAAAAAAa" << std::endl;
            }
        }

        window.clear(sf::Color(111, 111, 111));

        window.draw(*file_button);
        window.draw(*edit_button);
        window.draw(*brush_button);
        window.draw(file_text);
        window.draw(edit_text);
//        window.draw(test_image);

        window.display();
    }
    return 0;
}