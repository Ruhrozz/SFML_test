#include <gtest/gtest.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

TEST(sfml_check, test_eq) {
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
        break;
    }
    EXPECT_EQ(1, 1);
}

