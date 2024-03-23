
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "star.h"
#include "planet.h"


using namespace std;

int main()
{
    /*
    unique_ptr<spaceObject> objekty[]
        = {
        make_unique<star>(),
        make_unique<star>()
    };
    
    
        cout << "\nCalling objects\n";

    for (auto& volanyObjekt : objekty)
    {
        volanyObjekt->call();
    }

    
    */

    cout << "create objects\n";

    star slunce{ 100 };
    planet zeme{ 10, slunce };
    



    sf::CircleShape circle(50);
    circle.setFillColor(sf::Color::Red);
    circle.setPosition(600 - circle.getRadius(), 400 - circle.getRadius());

    //UPDATE
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Solar System Creator");
    while (window.isOpen())
    {


        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }



        window.clear();

        slunce.draw(window);
        zeme.draw(window);

        window.display();
    }

    cout << "\nDestroing objects\n";
    return 0;
}