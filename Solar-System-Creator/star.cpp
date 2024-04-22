#include "star.h"
#include <iostream>

using namespace std;

star::star()
	:m_radius{}
{
	cout << __FUNCTION__ << "\n";
}

star::~star()
{
	cout << __FUNCTION__ << "\n";
}

star::star(const float& radius)
	: m_radius {radius}
{
	cout << __FUNCTION__ << "\n";

}


float star::getRadius() const
{
	return m_radius;
}

int star::getOrder() const
{
	return 0;
}

spaceObject* star::getConnection() const
{
	return nullptr;
}

void star::setRadius(const float& radius)
{
	m_radius = radius;
}

void star::setOrder(const int& order)
{
}

void star::setOrbit(orbit* newOrbit)
{
}


void star::setConnection(spaceObject* connectedTo)
{
}

void star::setColorWheel()
{
}

void star::draw(sf::RenderWindow& window)
{
	sf::CircleShape starObj(m_radius);
	starObj.setFillColor(sf::Color::Yellow);
	starObj.setPosition(300 - starObj.getRadius(), 300 - starObj.getRadius());

	window.draw(starObj);
}


sf::Vector2f star::getPosition() const
{
	return sf::Vector2f(300 , 300);
}
