
/*
TODO MLY 2024-04-16: dynamicky vytvorene orbity!
TODO MLY 2024-04-16: Oznaceni konkretni planety!
TODO MLY 2024-04-16: pridana planeta s odkazem na oznacenou planetu 
TODO MLY 2024-04-16: dopln vesmirna telesa



*/

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include "star.h"
#include "planet.h"
#include "background.h"

using namespace std;


class solarSystemCreator
{
public:
    void setSpaceObject();
    void update();
    void drawing(sf::RenderWindow &window);
    void getAdresses();

private:
    background m_background;
};

void solarSystemCreator::setSpaceObject()
{
    float starSize = 50.f;
    auto slunce = std::make_shared<star>(starSize);
    m_background.add(slunce);

    //Dynamicky tvorene orbity
    float starConnection = starSize+20;
    float nonStarConnection = 10;
    auto planet1 = std::make_shared<planet>(10.0f, *slunce, 0, starConnection,  0.f, 0.005f);
    m_background.add(planet1);
    auto planet2 = std::make_shared<planet>(9.0f, *slunce, 0, starConnection *2,  180.f, 0.006f);
    m_background.add(planet2);
    auto planet3 = std::make_shared<planet>(3.0f, *planet1, 0, nonStarConnection,  0.f, 0.03f);
    m_background.add(planet3);
    auto planet4 = std::make_shared<planet>(2.f, *planet3, 0, nonStarConnection *2,  0.f, 0.06f);
    m_background.add(planet4);
    auto planet5 = std::make_shared<planet>(8.f, *slunce, 0, starConnection *3, 160.f, 0.009f);
    m_background.add(planet5);
    auto planet6 = std::make_shared<planet>(7.f, *slunce, 0, starConnection * 4, 160.f, 0.009f);
    m_background.add(planet6);
    auto planet7 = std::make_shared<planet>(4.f, *planet1, 0, nonStarConnection * 4, 160.f, 0.009f);
    m_background.add(planet7);
    auto planet8 = std::make_shared<planet>(3.f, *planet1, 0, nonStarConnection * 4, 160.f, 0.009f);
    m_background.add(planet8);
    //!
    //auto planet7 = std::make_shared<planet>(
    // 0,1f < sizeOfPlanet1, 
    // *planet1, 
    // orderOnPlanet1 radiusPlanet1 + radiusPlanet7 + (10 * orderOnPlanet1) 
    // , rand, rand);
    
    //m_background.add(planet7);
}

void solarSystemCreator::update()
{

    m_background.update();
}

void solarSystemCreator::drawing(sf::RenderWindow &win)
{
    m_background.draws(win);

}

void solarSystemCreator::getAdresses()
{
    m_background.getSpaceObjPtrVec();
}



solarSystemCreator m_solarSystemCreator;



int main()
{
    std::cout << "create objects\n";
    m_solarSystemCreator.setSpaceObject();
    //m_solarSystemCreator.getAdresses();



    //UPDATE
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Solar System Creator");
    while (window.isOpen())
    {
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            window.close();
        }

        m_solarSystemCreator.update();


        sf::Color backgroudColor(sf::Color::Black);
        window.clear(backgroudColor);

        m_solarSystemCreator.drawing(window);


        window.display();
    }

    std::cout << "\nDestroing objects\n";
    return 0;
}

