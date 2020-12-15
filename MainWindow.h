#pragma once
#include <SFML/Graphics.hpp>
#include "Model.h"

class MainWindow
{
    public:
        MainWindow() = default;
        MainWindow(int width, int height);
        ~MainWindow() = default;
        int Start();
    private:
        void UpdateWindow();
        void ButtonPressed();
        void Roll(int lines);
        sf::Font font;
        sf::Text text;
        sf::RenderWindow *window;
        Model model;
        int symbolHeight;
        sf::Color fillColor;
        sf::Texture texture;
        sf::RectangleShape background;

}; 