#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	
	sf::Font font; 
	font.loadFromFile("OpenSans-Regular.ttf");
	sf::Text visible;
	visible.setFont(font);
	visible.setPosition(10, 10);
	visible.setCharacterSize(11);
	sf::RenderWindow window(sf::VideoMode(600, 600), "hack");
	sf::Color fillColor = sf::Color(255, 255, 255);
	visible.setFillColor(sf::Color::Blue);
	ifstream MyReadFile("text.txt");
	string myText;
	int i = 0;
	string changingText = "";
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();			
			}
			if (event.type == sf::Event::KeyReleased)
			{
				if (i < 0)
				{
					getline (MyReadFile, changingText);
					i = 0;
				}	
				if (changingText.length() != 0)
				{
					myText = myText + changingText[i];
				}
				i++;
				if (i >= changingText.length())
				{
					i = -2;
					myText = myText + "\n";
				}
				visible.setString(myText);
			}
		} 
		window.clear(fillColor);
		window.draw(visible);
		window.display();
	}

	return 0;
}
