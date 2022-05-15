#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

class Window{
public:
	int height;
	int width;
Window(){
	height = 1200;
	width = 1000;
}
Window(int x,int y)
{
	width = x;
	height = y;
}
	

};

class Player
{
public:
	int height_of_player;
	int width_of_player;
Player(){
	height_of_player = 50;
	width_of_player = 50;

}
Player(int x, int y){
	height_of_player = y;
	width_of_player = x;

}
};

class Enemy
{
public:
int speed;
int is_the_game_over = 0;

Enemy(){
	speed = 3;
	is_the_game_over = 0;
}

};

Enemy enn1;
Enemy enn2;
Enemy enn3;

void Update(int& keyTime, sf::RectangleShape& square, sf::RenderWindow& window,sf::RectangleShape& en1,sf::RectangleShape& en2,sf::RectangleShape& en3);
void Draw(sf::RenderWindow& window, sf::RectangleShape& square,sf::RectangleShape& en1,sf::RectangleShape& en2,sf::RectangleShape& en3);

int main() 
{
	Window window1;
	Player player1;

	int keyTime = 0;
	sf::RenderWindow window(sf::VideoMode(window1.height, window1.width), "Agar.io");
	window.setFramerateLimit(60);

	sf::RectangleShape square(sf::Vector2f(player1.width_of_player, player1.height_of_player));
	square.setFillColor(sf::Color::Green);
	square.setPosition(window.getSize().x / 2, window.getSize().y / 2 );

	sf::RectangleShape en1(sf::Vector2f(60, 60));
	en1.setFillColor(sf::Color::Red);
	en1.setPosition(window.getSize().x / 3, window.getSize().y / 3 );

	sf::RectangleShape en2(sf::Vector2f(60, 60));
	en2.setFillColor(sf::Color::Red);
	en2.setPosition(200,700);

	sf::RectangleShape en3(sf::Vector2f(60, 60));
	en3.setFillColor(sf::Color::Yellow);
	en3.setPosition(700,200);

	while (window.isOpen())
	{
		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				window.close();
		}

		Update(keyTime,square,window,en1,en2,en3);
		if(enn3.is_the_game_over == 1)
		{
			sf::Text text;
			text.setString("Przegrałeś");
			text.setCharacterSize(24);
			text.setFillColor(sf::Color::White);
			text.setPosition((window1.width/2),(window1.height/2));
			window.draw(text);
			window.display();
			//break;
		}
		Draw(window,square,en1,en2,en3);

	}

	




	return 0;
};

void Update(int& keyTime, sf::RectangleShape& square, sf::RenderWindow& window, sf::RectangleShape& en1,sf::RectangleShape& en2, sf::RectangleShape& en3)
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

	sf::Vector2f position = square.getPosition(); 

	//int a = enn1.speed;

	window.draw(en1);
	sf::Vector2f position2 = en1.getPosition(); 

	float odleglosc_x = position.x - position2.x;
	float odleglosc_y = position.y - position2.y;
	odleglosc_x = odleglosc_x /50;
	odleglosc_y = odleglosc_y /50;
	en1.move(odleglosc_x,odleglosc_y);


	window.draw(en3);
	int a = enn3.speed;
	sf::Vector2f position3 = en3.getPosition(); 
	float odleglosc_xx = position.x - position3.x;
	float odleglosc_yy = position.y - position3.y;
	
	if (odleglosc_xx > 0){
		odleglosc_xx = a;
	}
	else if(odleglosc_xx < 0){
		odleglosc_xx = - a;
	}
	else if(odleglosc_xx == 0){
		cout<<"You lost";
		enn3.is_the_game_over = 1;
	}

	if (odleglosc_yy > 0){
		odleglosc_yy = a;
	}
	else if(odleglosc_yy < 0){
		odleglosc_yy = - a;
	}
	else if(odleglosc_yy == 0){
		cout<<"You lost";
		enn3.is_the_game_over = 1;
		
	}

	en3.move(odleglosc_xx,odleglosc_yy);

	

	int aa = enn2.speed;
	int bb;
	int cc;
	window.draw(en1);
	bb = (rand() % 2) + 1;
	cc = (rand() % 2) + 1;
	if(bb == 1){aa = -aa;}
	if(cc == 1 ){en2.move(a,0);} else{en2.move(0,aa);}

        
}
void Draw(sf::RenderWindow& window, sf::RectangleShape& square,sf::RectangleShape& en1,sf::RectangleShape& en2,sf::RectangleShape& en3)
{
	window.clear(sf::Color::Black);
	window.draw(square);
	window.draw(en1);
	window.draw(en2);
	window.draw(en3);
	window.display();
}

