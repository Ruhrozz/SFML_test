#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include <vector>


sf::RectangleShape *getButton(float width, float height, float x, float y, sf::Color color) {
    auto button = new sf::RectangleShape(sf::Vector2f(width, height));
    button->setFillColor(color);   //158, 158, 158
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
    const float INIT_RESOLUTION[] = {800, 600};
    bool isFullscreen = false;
    bool isDrawing = false;
    
    std::vector<sf::Vertex> buffer_vertex;
    
    int lines_size = 100;
    auto lines = new sf::Vertex[lines_size];
    int lines_pos = 0;
    
    
    sf::RenderWindow window(sf::VideoMode(INIT_RESOLUTION[0], INIT_RESOLUTION[1]), "My window", sf::Style::None);
    window.setVerticalSyncEnabled(true);


    std::map <std::string, sf::RectangleShape*> buttons;
    std::map <std::string, sf::Text*> labels;

    buttons["border_top"] = getButton(5000, 40, 0, 0, sf::Color(70, 70, 70));
    buttons["border_left"] = getButton(50, 5000, 0, 0, sf::Color(70, 70, 70));
    buttons["border_right"] = getButton(5000, 5000, 350, 0, sf::Color(70, 70, 70));
    buttons["border_bot"] = getButton(5000, 5000, 0, 340, sf::Color(70, 70, 70));

    buttons["file"] = getButton(50, 30, 0, 0, sf::Color(140, 140, 140));
    buttons["edit"] = getButton(50, 30, 52, 0, sf::Color(140, 140, 140));
    buttons["quit"] = getButton(30, 30, INIT_RESOLUTION[0] - 30 , 0, sf::Color(140, 140, 140));
    buttons["resize"] = getButton(30, 30, INIT_RESOLUTION[0] - 62 , 0, sf::Color(140, 140, 140));


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
                buttons["file_opened"] = getButton(100, 200, 0, 32, sf::Color(140, 140, 140));
            }
            else
            {
                buttons.erase("file_opened");
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
                    buttons["quit"] = getButton(30, 30, sf::VideoMode::getDesktopMode().width - 30, 0, sf::Color(140, 140, 140));
                    buttons["resize"] = getButton(30, 30, sf::VideoMode::getDesktopMode().width - 62 , 0, sf::Color(140, 140, 140));
                }
                else
                {
                    window.create(sf::VideoMode(INIT_RESOLUTION[0], INIT_RESOLUTION[1]), "My window", sf::Style::None);
                    buttons["quit"] = getButton(30, 30, INIT_RESOLUTION[0] - 30 , 0, sf::Color(140, 140, 140));
                    buttons["resize"] = getButton(30, 30, INIT_RESOLUTION[0] - 62 , 0, sf::Color(140, 140, 140));
                }

                isFullscreen = !isFullscreen;
            }
        }

        window.clear(sf::Color(111, 111, 111));
    
        
        
        bool prevIsDrawing = isDrawing;
    
        auto win_pos = sf::Mouse::getPosition(window);
        float pos_x = win_pos.x;
        float pos_y = win_pos.y;
        
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) )
        {
            if(lines_pos >= lines_size - 10)
            {
                lines_size *= 2;
                auto *new_lines = new sf::Vertex[lines_size];
                for(int i = 0; i < lines_pos; ++i)
                    new_lines[i] = lines[i];
                delete [] lines;
                lines = new_lines;
            }
            
            if(!isDrawing)
            {
                lines[lines_pos++].position = sf::Vector2f(pos_x, pos_y);
                isDrawing = true;
            }
    
            lines[lines_pos++].position = sf::Vector2f(pos_x, pos_y);
            lines[lines_pos++].position = sf::Vector2f(pos_x, pos_y);
        }
        else
        {
            isDrawing = false;
        }
        
        if(prevIsDrawing and !isDrawing)
            lines[lines_pos++].position = sf::Vector2f(pos_x, pos_y);
        
        window.draw(lines, lines_pos, sf::Lines);
    
        for(auto& item : buttons)
            window.draw(*item.second);
    
        for(auto& item : labels)
            window.draw(*item.second);
        
        window.display();
    }


    return 0;
}

