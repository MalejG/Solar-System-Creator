
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

private:
    background m_background;
};

void solarSystemCreator::setSpaceObject()
{
    auto slunce = std::make_shared<star>(50.0f);
    m_background.add(slunce);
    auto planet1 = std::make_shared<planet>(10.0f, *slunce, 200.f, 0.f, 0.005f);
    m_background.add(planet1);
    auto planet2 = std::make_shared<planet>(8.0f, *slunce, 300.f, 180.f, 0.006f);
    m_background.add(planet2);
    auto planet3 = std::make_shared<planet>(3.0f, *planet1, 30.f, 0.f, 0.03f);
    m_background.add(planet3);
    auto planet4 = std::make_shared<planet>(3.f, *planet3, 10.f, 0.f, 0.06f);
    m_background.add(planet4);
    auto planet5 = std::make_shared<planet>(5.f, *slunce, 200.f, 160.f, 0.009f);
    m_background.add(planet5);
}

void solarSystemCreator::update()
{

    m_background.update();
}

void solarSystemCreator::drawing(sf::RenderWindow &win)
{
    m_background.draws(win);

}



solarSystemCreator m_solarSystemCreator;

int main()
{
    std::cout << "create objects\n";
    m_solarSystemCreator.setSpaceObject();



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

        m_solarSystemCreator.update();


        sf::Color backgroudColor(sf::Color::Black);
        window.clear(backgroudColor);

        m_solarSystemCreator.drawing(window);


        window.display();
    }

    std::cout << "\nDestroing objects\n";
    return 0;
}

