
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

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
    planet planet1{ 10, slunce, 200, 0, 0.005f };
    planet planet2{ 8, slunce, 300, 180, 0.006f };
    planet planet3{ 3, planet1, 30, 0, 0.03f };
    planet planet4{ 3, planet3, 10, 0, 0.06f };


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

        planet1.update();
        planet2.update();
        planet3.update();
        planet4.update();

        sf::Color backgroudColor(100, 100, 100);
        window.clear(backgroudColor);

        slunce.draw(window);
        planet1.draw(window);
        planet2.draw(window);
        planet3.draw(window);
        planet4.draw(window);

        window.display();
    }

    cout << "\nDestroing objects\n";
    return 0;
}