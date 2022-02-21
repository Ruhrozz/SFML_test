#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

sf::RectangleShape *getButton(float width, float height, float x, float y) {
    auto button = new sf::RectangleShape(sf::Vector2f(width, height));
    button->setFillColor(sf::Color(140, 140, 140));   //158, 158, 158
    button->setPosition(sf::Vector2f(x, y));
    return button;
}

sf::Text *getText(const sf::Font& font, const sf::String &str, float x, float y, unsigned int CharacterSize = 15)
{
    auto text = new sf::Text;
    text->setFont(font);
    text->setCharacterSize(CharacterSize);
    text->setString(str);
    text->setPosition(sf::Vector2f(x, y));
    return text;
}


int main()
{
    bool isFullscreen = false;

    //todo::create button for resize
    sf::RenderWindow window(sf::VideoMode(1024, 768), "My window", sf::Style::None);
    window.setVerticalSyncEnabled(true);

    //TODO: create shapes and pictures array
    auto file_button = getButton(50, 30, 0, 0);
    auto edit_button = getButton(50, 30, 52, 0);
    auto brush_button = getButton(300, 300, 50, 40);
    auto quit_button = getButton(30, 30, 1024 - 30 , 0);

    sf::RectangleShape * buttons[] = {file_button, edit_button, brush_button, quit_button};
    //--------------------STRINGS-------------------------//
    sf::Font font;
    std::string path("..\\fonts\\ArialRegular.ttf");
    font.loadFromFile(path);

    auto file_text = getText(font, "File", 13, 7, 15);
    auto edit_text = getText(font, "Edit", 65, 7, 15);
    sf::Text * texts[] = {file_text, edit_text};
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
            {
                window.create(sf::VideoMode::getDesktopMode(), "My window", sf::Style::Fullscreen);
                quit_button = getButton(30, 30, sf::VideoMode::getDesktopMode().width - 30, 0);
            }
            else
            {
                window.create(sf::VideoMode(1024, 768), "My window");
                quit_button = getButton(30, 30, 1024 - 30 , 0);
            }
            isFullscreen = !isFullscreen;
            while(sf::Keyboard::isKeyPressed(sf::Keyboard::F5))
                ;
        }
        //todo: maybe rewrite as "switch — case" construction or cycle? also maybe 77-83 apply to resize button
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i mouse = sf::Mouse::getPosition(window);
            if (file_button->getGlobalBounds().contains(mouse.x, mouse.y))
            {
                std::cout << "AAAAAAAAAAAAAAAa" << std::endl;
            }
            if (quit_button->getGlobalBounds().contains(mouse.x, mouse.y))
            {
                window.close();
            }
        }

        window.clear(sf::Color(111, 111, 111));
        for(auto & button : buttons) window.draw(*button);
        for (auto & text : texts) window.draw(*text);

//      window.draw(test_image);

        window.display();
    }
    return 0;
}

