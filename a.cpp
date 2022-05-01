#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

void Update(int& keyTime, sf::RectangleShape& square, sf::RenderWindow& window);
void Draw(sf::RenderWindow& window, sf::RectangleShape& square);

int main() 
{
	int keyTime = 0;
	sf::RenderWindow window(sf::VideoMode(800, 600), "Agar.io");
	window.setFramerateLimit(60);

	sf::RectangleShape square(sf::Vector2f(40.f, 40.f));
	square.setFillColor(sf::Color::Green);
	square.setPosition(window.getSize().x / 2, window.getSize().y / 2 );


	while (window.isOpen())
	{
		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				window.close();
		}

		Update(keyTime,square,window);
		Draw(window,square);

	}

	return 0;
};

void Update(int& keyTime, sf::RectangleShape& square, sf::RenderWindow& window)
{
	if (keyTime < 8)
	{
		keyTime++;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && square.getPosition().y > 0)
	{
		square.move(0.f, -5.f);
		keyTime = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && square.getPosition().x > 0)
	{
		square.move(-5.f, 0.f);
		keyTime = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && square.getPosition().y + square.getSize().y < window.getSize().y)
	{
		square.move(0.f, 5.f);
		keyTime = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && square.getPosition().x + square.getSize().x<window.getSize().x)
	{
		square.move(5.f, 0.f);
		keyTime = 0;
	}
}
void Draw(sf::RenderWindow& window, sf::RectangleShape& square)
{
	window.clear(sf::Color::Black);
	window.draw(square);
	window.display();
}