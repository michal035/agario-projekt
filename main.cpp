#include "Bazowa.h"

#include "Ball.h"
#include "Punkty.h"
#include "Przeciwnik.h"
#include "Ofiara.h"

#include <iostream>

//Klasa szablonowa pobierająca zmienne różnych klas, która dzięki funkcją sprawdzania: right, left, top i bottom
//Sprawdza czy boiekty się nachodzą. Będzię wykorzystywana do collisionTest
template <class C1,class C2> bool isIntersecting(C1& A, C2& B)
{
    return A.right()>=B.left() && A.left()<=B.right()
     && A.bottom()>=B.top()&&A.top()<=B.bottom();
}

//Funkcje opierające się na klasie szablonowej. Sprawdzają one przecięcie i na tej podstawie pokazują się różne wyniki

bool collisionTestPoints(Ball& ball, Punkty& punkt)
{
    if(!isIntersecting(ball,punkt)) return false;

//tutaj dodać metode niszczącą obiekty typu Punkty
    std::cout<<"Kolizja punktu, ";
    
    
}

bool collisionTestHunted(Ball& ball, Ofiara& ofiara)
{
    if(!isIntersecting(ball,ofiara)) return false;

//tutaj dodać metode niszczącą obiekty typu Ofiara
    std::cout<<"Kolizja ofiary, ";
    
    
}

bool collisionTestOponent(Ball& ball, Przeciwnik& przeciwnik)
{
    if(!isIntersecting(ball,przeciwnik)) return false;

//tutaj dodać metodę wyświetlającą game over
    std::cout<<"Kolizja przeciwnika, ";
    
    
}



int main()
{
    //srand(time(NULL));
    
    Ball ball(512,384,10.f,3.f);
    Przeciwnik przeciwnik(300,200,30.f,3.f);
    Punkty punkt(300,200,30.f);
    Ofiara ofiara(0,0,30.f,3.f);

    

    RenderWindow window{VideoMode(1024,768),"Arcanoid Tutorial"};
    window.setFramerateLimit(60);

    Event event;

    //int _x,_y;
    

    while(true) //Działanie okna
    {
        window.clear(Color::Black);

            window.pollEvent(event); // Pozwala nie frezzować kompa 

            if(event.type==Event::Closed)
            {
                window.close();
                break;
            }
                          
    //while(i<3)
   // {
       // _x=rand()%1023+2;
       // _y=rand()%767+2;
       // Punkty punkt(_x,_y,50.f);
        //window.draw(punkt);
       // i++;
    //}

     
            ball.update();
            przeciwnik.update();
            ofiara.update();

            window.draw(ball);
            window.draw(przeciwnik);
            window.draw(punkt);
            window.draw(ofiara);

            collisionTestPoints(ball,punkt);
            collisionTestHunted(ball,ofiara);
            collisionTestOponent(ball,przeciwnik);

            

        window.display(); //wywoływanie obiektów 
    }

    return 0; 
}