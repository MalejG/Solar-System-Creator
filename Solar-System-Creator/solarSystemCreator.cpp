
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "spaceObject.h"
#include "star.h"


using namespace std;

int main()
{
    cout << "create objects\n";

    unique_ptr<spaceObject> objekty[]
        = {
        make_unique<star>(),
        make_unique<star>()
    };
    cout << "\nstart calling objects\n";
    
    for (auto& volanyObjekt : objekty) 
    {
        volanyObjekt->call();
    }

    cout << "\nstop calling objects\n";


    sf::RenderWindow window(sf::VideoMode(1200, 800), "Solar System Creator");
    while (window.isOpen())
    {
        sf::CircleShape circle(50);
        circle.setFillColor(sf::Color::Red);

        circle.setPosition(600 - circle.getRadius(), 400 - circle.getRadius());
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        window.draw(circle);
        
        window.display();
    }

    return 0;
}