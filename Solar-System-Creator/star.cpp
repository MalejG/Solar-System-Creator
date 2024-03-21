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

star::star(const int& radius)
	: m_radius {radius}
{
}

void star::call()
{
	cout << "\nim star";
}

int star::getRadius() const
{
	return m_radius;
}

spaceObject* star::getConnection() const
{
	return nullptr;
}

void star::setRadius(const int& radius)
{
	m_radius = radius;
}

void star::setConnection(spaceObject* connectedTo)
{
}
