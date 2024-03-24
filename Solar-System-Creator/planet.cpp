#include "planet.h"

#include <iostream>

using namespace std;

planet::planet()
	: m_radius {10}
	, m_connectedTo {}
	, m_orbit{ }

{
	cout << __FUNCTION__ << "\n";
}

planet::~planet()
{
	cout << __FUNCTION__ << "\n";
}

planet::planet(const float& radius, spaceObject& connected, float orbitRadius, float orbitAngle, float orbitSpeed)
	: m_radius { radius }
, m_connectedTo{ &connected }
, m_orbit{ new orbit(&connected, orbitRadius, orbitAngle, orbitSpeed) }
{
	cout << __FUNCTION__ << "\n";
}

float planet::getRadius() const
{
	return m_radius;
}


spaceObject* planet::getConnection() const
{
	return *m_connectedTo.begin();
}


void planet::setRadius(const float& radius)
{
	m_radius = radius;
}

void planet::setConnection(spaceObject* connectedTo)
{
	m_connectedTo.insert(connectedTo);
}

void planet::draw(sf::RenderWindow& window)
{
	sf::Vector2f position = getPosition();
	sf::CircleShape planetObj(m_radius);\
	planetObj.setPosition(position.x - m_radius, position.y - m_radius);
	planetObj.setFillColor(sf::Color::Green);
	window.draw(planetObj);

}


sf::Vector2f planet::getPosition() const
{
	return m_orbit->getPosition();
}

void planet::update()
{
	if (m_orbit)
	{
		m_orbit->update();
	}
}
