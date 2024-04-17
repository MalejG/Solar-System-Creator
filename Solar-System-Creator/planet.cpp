#include "planet.h"

#include <iostream>

using namespace std;

colorWheel planet::m_wheel;

planet::planet()
	: m_radius {10}
	, m_connectedTo {}
	, m_order{ 0 }
	, m_orbit{ }

{
	cout << __FUNCTION__ << "\n";
	setColorWheel();
}

planet::~planet()
{
	cout << __FUNCTION__ << "\n";
}

planet::planet(const float& radius, spaceObject& connected, int order, float orbitRadius, float orbitAngle, float orbitSpeed)
	: m_radius { radius }
, m_connectedTo{ &connected }
, m_order { order }
, m_orbit{ new orbit(&connected, orbitRadius, orbitAngle, orbitSpeed) }
{
	setColorWheel();
	cout << __FUNCTION__ << "\n";
}

float planet::getRadius() const
{
	return m_radius;
}

int planet::getOrder() const
{
	return m_order;
}


spaceObject* planet::getConnection() const
{
	return *m_connectedTo.begin();
}

void planet::setOrder(const int& order)
{
	m_order = order;
}


void planet::setRadius(const float& radius)
{
	//cout << "Value of radius: " << radius;
	//cout << "Memory address of radius: " << &radius;
	m_radius = radius;
}

void planet::setConnection(spaceObject* connectedTo)
{
	m_connectedTo.insert(connectedTo);
}

void planet::setColorWheel()
{
	m_color = m_wheel.getColor("planet");
}


void planet::setOrbit(orbit* newOrbit)
{
	m_orbit = newOrbit;
}


void planet::draw(sf::RenderWindow& window)
{
	sf::Vector2f position = getPosition();
	sf::CircleShape planetObj(m_radius);
	planetObj.setPosition(position.x - m_radius, position.y - m_radius);

	planetObj.setFillColor(m_color);
	
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
