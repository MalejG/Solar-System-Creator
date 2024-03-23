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
}

void star::call()
{
	cout << "\nim star";
}

float star::getRadius() const
{
	return m_radius;
}

spaceObject* star::getConnection() const
{
	return nullptr;
}

void star::setRadius(const float& radius)
{
	m_radius = radius;
}

void star::setConnection(spaceObject* connectedTo)
{
}

void star::draw(sf::RenderWindow& window)
{
	sf::CircleShape starObj(m_radius);
	starObj.setFillColor(sf::Color::Yellow);
	window.draw(starObj);
}
