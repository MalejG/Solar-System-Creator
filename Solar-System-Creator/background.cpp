#include "background.h"

background::background()
	: m_spaceObjects{  }
{
}

void background::add(spaceObjPtr utvar)
{
	m_spaceObjects.push_back(move(utvar));
	m_pickedSpaceObject = m_spaceObjects.size() - 1;
}

void background::update()
{
	for (size_t i = 0; i < m_spaceObjects.size(); i++)
	{
		m_spaceObjects[i]->update();
	}
}


void background::draws(sf::RenderWindow &window)
{
	for (size_t i = 0; i < m_spaceObjects.size(); i++)
	{
		m_spaceObjects[i]->draw(window);
	}
}

//for understand what is going on with vector and adresses
void background::getSpaceObjPtrVec()
{
	for (size_t i = 0; i < m_spaceObjects.size(); i++)
	{
		cout << " " << i << ": " << &m_spaceObjects[i] << "  ";
	}
	cout << "\n";

	for (size_t i = 0; i < m_spaceObjects.size(); i++)
	{
		cout << " " << i << ": " << m_spaceObjects[i] << "  ";
	}
}

void background::dynamicOrbit()
{
	for (size_t i = 0; i < m_spaceObjects.size(); i++)
	{
		//dynamicky vytvorene orbity
	}
}
