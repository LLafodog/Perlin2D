#include <iostream>

#include<cstdlib>
#include<ctime>

#include "Perlin.h"

/// Graphic
#include<SFML/Graphics.hpp>

#define TS 5
#define NT 100
#define STEP 10

#define SEA 50
#define SAND 100
#define GROUND 200

using namespace std;
using namespace sf;

int main()
{
    srand(time(NULL));

    Perlin* p=new Perlin(91,58,STEP);
    p->display(); // numbers
    RectangleShape rc(Vector2f(TS,TS));
    RenderWindow window(  VideoMode((NT-STEP)*TS,TS*(NT-STEP)),"Perlin_2D");

    while(window.isOpen())
    {
        Event event;
        while(window.pollEvent(event))
        {
            switch(event.type)
            {
            case Event::Closed : window.close(); break;
            case Event::KeyPressed:
            {
                switch(event.key.code)
                {
                default:break;
                case Keyboard::Escape: window.close();break;
                }
            }break;
            default:break;
            }
        }

        window.clear(Color(4,139,154));

        for(int i(0);i<p->getHeight();i++)
        {
            for(int j(0);j<p->getWidth();j++)
            {
                rc.setPosition(i*TS,j*TS);
                double value=p->get(i,j);
                /// GREY
                rc.setFillColor(Color(value,value,value));
                /// COLORS
/*
                if(value<=SEA){rc.setFillColor(Color::Blue);}
                if(value > SEA && value<=SAND){rc.setFillColor(Color::Yellow);}
                if(value > SAND && value<=GROUND ){rc.setFillColor(Color::Green);}
                if(value > GROUND){rc.setFillColor(Color::Black);}
*/
                ///
                window.draw(rc);
            }
        }

        window.display();
    }



    delete p;
    return 0;
}
