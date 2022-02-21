#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>


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
    const float INIT_SCREEN[] = {800, 600};
    bool isFullscreen = false;


    sf::RenderWindow window(sf::VideoMode(INIT_SCREEN[0], INIT_SCREEN[1]), "My window", sf::Style::None);
    window.setVerticalSyncEnabled(true);


    std::map <std::string, sf::RectangleShape*> buttons;
    std::map <std::string, sf::Text*> labels;


    buttons["file"] = getButton(50, 30, 0, 0);
    buttons["edit"] = getButton(50, 30, 52, 0);
    buttons["brush"] = getButton(300, 300, 50, 40);
    buttons["quit"] = getButton(30, 30, INIT_SCREEN[0] - 30 , 0);
    buttons["resize"] = getButton(30, 30, INIT_SCREEN[0] - 62 , 0);


    sf::Font font;
    std::string path("..\\fonts\\ArialRegular.ttf");
    font.loadFromFile(path);

    labels["file"] = getText(font, "File", 13, 7, 15);
    labels["edit"] = getText(font, "Edit", 65, 7, 15);


    while (window.isOpen())
    {
        sf::Event event{};

        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();


        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i mouse = sf::Mouse::getPosition(window);

            if (buttons["file"]->getGlobalBounds().contains(mouse.x, mouse.y))
            {
                std::cout << "AAAAAAAAAAAAAAAa" << std::endl;
            }

            if (buttons["quit"]->getGlobalBounds().contains(mouse.x, mouse.y))
            {
                window.close();
            }

            if (buttons["resize"]->getGlobalBounds().contains(mouse.x, mouse.y))
            {
                while(sf::Mouse::isButtonPressed(sf::Mouse::Left));

                window.close();

                if(!isFullscreen)
                {
                    window.create(sf::VideoMode::getDesktopMode(), "My window", sf::Style::Fullscreen);
                    buttons["quit"] = getButton(30, 30, sf::VideoMode::getDesktopMode().width - 30, 0);
                    buttons["resize"] = getButton(30, 30, sf::VideoMode::getDesktopMode().width - 62 , 0);
                }
                else
                {
                    window.create(sf::VideoMode(INIT_SCREEN[0], INIT_SCREEN[1]), "My window", sf::Style::None);
                    buttons["quit"] = getButton(30, 30, INIT_SCREEN[0] - 30 , 0);
                    buttons["resize"] = getButton(30, 30, INIT_SCREEN[0] - 62 , 0);
                }

                isFullscreen = !isFullscreen;
            }
        }


        window.clear(sf::Color(111, 111, 111));


        for(auto& item : buttons)
            window.draw(*item.second);

        for(auto& item : labels)
            window.draw(*item.second);


        window.display();
    }


    return 0;
}

