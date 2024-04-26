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
    void keyLeft();
    void keyRight();
    void addSO();

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

    auto planet2 = std::make_shared<planet>(20.0f, *slunce, 0, starConnection *2,  180.f, 0.006f);
    m_background.add(planet2);
    auto planet5 = std::make_shared<planet>(16.f, *slunce, 0, starConnection *3, 160.f, 0.009f);
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

void solarSystemCreator::getAdresses()
{
    m_background.getSpaceObjPtrVec();
}

void solarSystemCreator::keyLeft()
{
    m_background.selectPrev();
}

void solarSystemCreator::keyRight()
{
    m_background.selectNext();

}

void solarSystemCreator::addSO()
{
    if(m_background.getSpaceObjVector()[m_background.getPickedSpaceObj()]->getConnection() == m_background.getSpaceObjVector()[0].get())
    {
        m_background.add(std::make_shared<planet>(7.0f, *m_background.getSpaceObjVector()[m_background.getPickedSpaceObj()], 1.f, 0, 0.f, 0.03f));
    }
    else if(m_background.getPickedSpaceObj() == 0)
    {
        m_background.add(std::make_shared<planet>(16.0f, *m_background.getSpaceObjVector()[m_background.getPickedSpaceObj()], 1.f, 0, 0.f, 0.03f));
    }
}



solarSystemCreator m_solarSystemCreator;



int main()
{
    std::cout << "create objects\n";
    m_solarSystemCreator.setSpaceObject();
    //m_solarSystemCreator.getAdresses();



    //UPDATE
    sf::RenderWindow window(sf::VideoMode(1600, 1600), "Solar System Creator");
    while (window.isOpen())
    {
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            window.close();
           
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
                else if (event.key.code == sf::Keyboard::Left) 
                {
                    m_solarSystemCreator.keyLeft();
                }
                else if (event.key.code == sf::Keyboard::Right)
                {
                    m_solarSystemCreator.keyRight();
                }
                else if (event.key.code == sf::Keyboard::K)
                {
                    m_solarSystemCreator.addSO();
                }
            }
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

