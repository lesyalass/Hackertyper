#include "MainWindow.h"
#include <string>

MainWindow::MainWindow(int width, int height)
{
    symbolHeight = 44;
    window = new sf::RenderWindow(sf::VideoMode(width, height), "Hackerman!");
    font.loadFromFile("../OpenSans-Regular.ttf");
    texture.loadFromFile("../back.png");
    background.setPosition({0,0});
    background.setSize({(float)window->getSize().x, (float)window->getSize().y});
    background.setTexture(&texture);
    text.setFont(font);
    text.setPosition(10, 0);
    text.setCharacterSize(symbolHeight);
    text.setColor(sf::Color(255, 165,0));
    text.setStyle(sf::Text::Bold);
    sf::Color fillColor = sf::Color(0, 0, 0);
}

int MainWindow::Start()
{
    while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window->close();			
			}
			if (event.type == sf::Event::KeyReleased)
			{
                ButtonPressed();
			}
            if (event.type == sf::Event::MouseWheelScrolled)
            {
                if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
                {
                    Roll(event.mouseWheelScroll.delta);
                }
            }            
		} 
		UpdateWindow();
	}
}

void MainWindow::UpdateWindow()
{
    window->clear(fillColor);
    text.setString(std::string(model.GetVisibleText().c_str()));
    window->draw(background);
    window->draw(text);
    window->display();
}

void MainWindow::ButtonPressed()
{
    model.AddSymbol();

    if(text.getPosition().y + text.getGlobalBounds().height > window->getSize().y)
    {
        Roll(-1);
    }
}

void MainWindow::Roll(int lines)
{
        text.move(0, lines * (1.2 * symbolHeight));
        if(text.getPosition().y > 10)
        {
            text.setPosition(10, 10);
        }
        else if(window->getSize().y - text.getPosition().y > text.getGlobalBounds().height )
        {
            text.setPosition(10, - text.getGlobalBounds().height + window->getSize().y - symbolHeight);
        }
}

