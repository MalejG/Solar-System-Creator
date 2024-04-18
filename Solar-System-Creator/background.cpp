#include "background.h"

background::background()
	: m_spaceObjects{  }
	, m_pickedSpaceObject {  }
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
	for (size_t i = 0; i < m_spaceObjects.size(); i++)
	{
		spaceObject* coonnectedTo = m_spaceObjects[i]->getConnection();
		int orderOnConnected = m_spaceObjects[i]->getOrder();
		float RadiusObject = m_spaceObjects[i]->getRadius();
		//oldOrbit = m_spaceObjects[i]->getOrbit();

		if (0 < orderOnConnected)
		{
			float newOrbitRadius = RadiusObject;
			for(size_t k = 0;k <= orderOnConnected;k++)
			{
				//musi propocitat vsechny planety predtim
				//potebuji pricist parent radius
				newOrbitRadius = newOrbitRadius + (k+1 * 20) + m_spaceObjects[k]->getRadius();
				if(k = orderOnConnected)
				{
					orbit* newOrbit = new orbit(coonnectedTo, newOrbitRadius, 0.f, 0.1f);
					m_spaceObjects[i]->setOrbit(newOrbit);
					break;
				}
			}
		}
	}


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
