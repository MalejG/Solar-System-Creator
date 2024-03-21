#include "planet.h"

#include <iostream>

using namespace std;
planet::planet()
	: m_radius {10}
	, m_connectedTo {}
{
	cout << __FUNCTION__ << "\n";
}

planet::~planet()
{
	cout << __FUNCTION__ << "\n";
}

planet::planet(const int& radius, spaceObject& connected)
	: m_radius { radius }
, m_connectedTo{ &connected }
{
}

int planet::getRadius() const
{
	return m_radius;
}


spaceObject* planet::getConnection() const
{
	return *m_connectedTo.begin();
}


void planet::setRadius(const int& radius)
{
	m_radius = radius;
}

void planet::setConnection(spaceObject* connectedTo)
{
	m_connectedTo.insert(connectedTo);
}



void planet::call()
{
	cout << "\nim planet";
}
