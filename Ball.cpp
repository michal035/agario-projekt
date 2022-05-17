#include "Ball.h"

String toString(int integer)
{
    char numstr[4];
    sprintf(numstr, "%i", integer);
    return numstr;
}




Ball::Ball(float t_X, float t_Y, float _ballRadius, float _ballVelocity)
{
    ballRadius=_ballRadius;
    ballVelocity=_ballVelocity;
    shape.setPosition(t_X,t_Y);
    shape.setRadius(this->ballRadius); //Ustawiamy radius
    shape.setFillColor(Color::White); //Ustawiamy kolor
 

        velocity.x=ballVelocity;//Pozwalamy classie pochodnej zdobyć jej wektor
        velocity.y=ballVelocity;//Bez tego piłka nie ruszy się

    shape.setOrigin(this->ballRadius,this->ballRadius);//Ustawiamy pozycje na podstawie wczesniejszej funkjci

}

void Ball::setMyText()
{
    font.loadFromFile("Terserah.ttf");

    gameLose.setFont(font);
    gameLose.setString("Game Over");
    gameLose.setCharacterSize(60);
    gameLose.setFillColor(Color::Red);
    gameLose.setOrigin(0,0);
    gameLose.setPosition(250,330);

    gameWin.setFont(font);
    gameWin.setString("Winner Winner Chicken Dinner");
    gameWin.setCharacterSize(60);
    gameWin.setFillColor(Color::Green);
    gameWin.setOrigin(0,0);
    gameWin.setPosition(75,330);

    scoreTxt.setFont(font);
    scoreTxt.setString(toString(score));
    scoreTxt.setCharacterSize(35);
    scoreTxt.setFillColor(Color::Blue);
    scoreTxt.setOrigin(0,0);
    scoreTxt.setPosition(0,0);
    
}

void Ball::update(){
    shape.move(this->velocity);//Metoda wbudowana w SFML do poruszania obiektów
    Bazowa::update();
    scoreTxt.setString(toString(score));
    
}


void Ball::kill(int i){
    if(i==1) score=score+50;
    else if(i==2) score=score+250;
    else score=0;
}

void Ball::draw(RenderTarget& target,RenderStates state) const
{
    target.draw(this->shape,state); //Metoda rysowania 
}


