#pragma once

#include "Bazowa.h"


//Klasa pochodna. Wykorzystuję zmienne kalsy Bazowej, które zmieniane są w konstruktorze
//Posiada metode rysowania odwołująca się do przekazywania obiektu referencyjnie(Funkcja SFML)

class Ball : public Bazowa {

public:
        Ball(float t_X, float t_Y, float _ballRadius, float _ballVelocity);

        Ball()=delete;
        ~Ball()=default;

        void update();
        void kill(int i);

        void setMyText();




        unsigned int score{100};
        Font font;
        Text gameLose;
        Text gameWin;
        Text scoreTxt;


private:
        
        void draw(RenderTarget& target, RenderStates state) const override; //rysowanie kulki

};

