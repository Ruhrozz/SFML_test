#include <gtest/gtest.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

TEST(font_check, test_eq) {
    sf::Font font;
    std::string path(R"(/home/ruhrozz/Desktop/study/MPPSD/SFML_test/src/fonts/ArialRegular.ttf)");

    auto val = font.loadFromFile(path);

    EXPECT_EQ(!val, 0);
}
