#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <map>
#include <vector>
#include "../lib/Buttons.h"
#include "../lib/Text.h"


int main()
{
    const std::array<int, 2> INIT_RESOLUTION = {1280, 720};
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

    buttons["l0_border_top"] = Buttons::getButton(5000, 40, 0, 0, sf::Color(70, 70, 70));
    buttons["l0_border_left"] = Buttons::getButton(50, 5000, 0, 0, sf::Color(70, 70, 70));
    buttons["l0_border_right"] = Buttons::getButton(5000, 5000, 350, 0, sf::Color(70, 70, 70));
    buttons["l0_border_bot"] = Buttons::getButton(5000, 5000, 0, 340, sf::Color(70, 70, 70));

    buttons["l1_file"] = Buttons::getButton(50, 30, 0, 0, sf::Color(140, 140, 140));
    buttons["l1_edit"] = Buttons::getButton(50, 30, 52, 0, sf::Color(140, 140, 140));
    buttons["l1_quit"] = Buttons::getButton(30, 30, (float)INIT_RESOLUTION[0] - 30 , 0, sf::Color(140, 140, 140));
    buttons["l1_resize"] = Buttons::getButton(30, 30, (float)INIT_RESOLUTION[0] - 62 , 0, sf::Color(140, 140, 140));


    sf::Font font;
    std::string path(R"(/home/ruhrozz/Desktop/study/MPPSD/SFML_test/src/fonts/ArialRegular.ttf)");

    if (!font.loadFromFile(path))
        return EXIT_FAILURE;

    labels["l1_file"] = Text::getText(font, "File", 13, 7, 15);
    labels["l1_edit"] = Text::getText(font, "Edit", 65, 7, 15);


    while (window.isOpen())
    {
        sf::Event event{};

        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i mouse = sf::Mouse::getPosition(window);

            if (buttons["l1_file"]->getGlobalBounds().contains((float)mouse.x, (float)mouse.y))
            {
                buttons["l2_file_isOpened"] = Buttons::getButton(100, 200, 0, 32, sf::Color(140, 140, 140));
    
                buttons["l3_file_New"] = Buttons::getButton(96, 20, 2, 34, sf::Color(90, 90, 90));
                labels["l3_file_New"] = Text::getText(font, "New", 6, 34, 15);
                
                buttons["l3_file_Save"] = Buttons::getButton(96, 20, 2, 56, sf::Color(90, 90, 90));
                labels["l3_file_Save"] = Text::getText(font, "Save", 6, 56, 15);
    
                buttons["l3_file_Open"] = Buttons::getButton(96, 20, 2, 78, sf::Color(90, 90, 90));
                labels["l3_file_Open"] = Text::getText(font, "Open", 6, 78, 15);
            }
            else
            {
                const auto found = buttons.find("l2_file_isOpened");
                
                if(found!=buttons.cend() && !buttons["l2_file_isOpened"]->getGlobalBounds().contains(mouse.x, mouse.y))
                {
                    buttons.erase("l2_file_isOpened");
    
                    buttons.erase("l3_file_New");
                    labels.erase("l3_file_New");
    
                    buttons.erase("l3_file_Save");
                    labels.erase("l3_file_Save");
    
                    buttons.erase("l3_file_Open");
                    labels.erase("l3_file_Open");
                }
            }

            if (buttons["l1_quit"]->getGlobalBounds().contains((float)mouse.x, (float)mouse.y))
            {
                window.close();
            }

            if (buttons["l1_resize"]->getGlobalBounds().contains((float)mouse.x, (float)mouse.y))
            {
                while(sf::Mouse::isButtonPressed(sf::Mouse::Left));

                window.close();

                if(!isFullscreen)
                {
                    window.create(sf::VideoMode::getDesktopMode(), "My window", sf::Style::Fullscreen);
                    buttons["l1_quit"] = Buttons::getButton(30, 30, (float)sf::VideoMode::getDesktopMode().width - 30, 0, sf::Color(140, 140, 140));
                    buttons["l1_resize"] = Buttons::getButton(30, 30, (float)sf::VideoMode::getDesktopMode().width - 62 , 0, sf::Color(140, 140, 140));
                }
                else
                {
                    window.create(sf::VideoMode(INIT_RESOLUTION[0], INIT_RESOLUTION[1]), "My window", sf::Style::None);
                    buttons["l1_quit"] = Buttons::getButton(30, 30, INIT_RESOLUTION[0] - 30 , 0, sf::Color(140, 140, 140));
                    buttons["l1_resize"] = Buttons::getButton(30, 30, INIT_RESOLUTION[0] - 62 , 0, sf::Color(140, 140, 140));
                }

                isFullscreen = !isFullscreen;
            }
        }

        window.clear(sf::Color(111, 111, 111));
    
        
        
        bool prevIsDrawing = isDrawing;
    
        auto win_pos = sf::Mouse::getPosition(window);
        auto pos_x = (float)win_pos.x;
        auto pos_y = (float)win_pos.y;
        
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
        
        if(prevIsDrawing && !isDrawing)
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

