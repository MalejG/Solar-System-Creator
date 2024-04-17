#include "background.h"

background::background()
	: m_spaceObjects{  }
{
}

void background::add(spaceObjPtr utvar)
{
	m_spaceObjects.push_back(move(utvar));
	m_pickedSpaceObject = m_spaceObjects.size() - 1;

	//najde kolik je jiz pripojenych objektu na jednom objektu(mozna projdi vsechny)
	searchOrder();

	
	//prenastavy orbity
	dynamicOrbit();
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

//po kazdem vytvoreni space objectu a prepocitani rady se musi prepocitat pozice orbitu u vazaneho objektu
void background::dynamicOrbit()
{


	//check planets
	for (size_t i = 0; i < m_spaceObjects.size(); i++)
	{

		cout << " Planet.Radius:"
			<< m_spaceObjects[i]->getRadius()
			<< " Connection:"
			<< m_spaceObjects[i]->getConnection()
			<< " Order:"
			<< m_spaceObjects[i]->getOrder();
		cout << "\n";
		 //m_spaceObjects[i]->getOrder();

		 //m_spaceObjects[i]->getOrder();

		//m_spaceObjects[i]->setOrbit(1);
	}
}

//prozkouma kolikata je v rade navazana na nejaky objekt a to mu priradi
void background::searchOrder()
{
	spaceObject* coonnectedTo = m_spaceObjects[m_spaceObjects.size()-1]->getConnection();
	int y = 0;
	for (size_t i = 0; i < m_spaceObjects.size(); i++)
	{
		if(coonnectedTo == m_spaceObjects[i]->getConnection())
		{
			y++;
			if (m_spaceObjects.size()-1 == i)
			{
				m_spaceObjects[m_spaceObjects.size() - 1]->setOrder(y);
			}
		}
	}
}
