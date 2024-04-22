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
		float parentRadius = 10;
		float newOrbitRadius = 0;

		if (coonnectedTo != nullptr)
		{
			parentRadius = parentRadius + coonnectedTo->getRadius();
		}

		for (size_t e = 0; e < m_spaceObjects.size(); e++)
		{ 
			if (m_spaceObjects[i].get() == m_spaceObjects[e]->getConnection())
			{
				newOrbitRadius = newOrbitRadius +  (m_spaceObjects[e]->getRadius() * 2) + 10 ;
			}
		}
		
		newOrbitRadius = newOrbitRadius + parentRadius + RadiusObject;

		if (0 < orderOnConnected)
		{
			for(size_t k = 0;k < orderOnConnected;k++)
			{
			
				//prochazi a nacita planety vazane k jednomu objektu
					for (size_t t = 0; t < m_spaceObjects.size(); t++)
					{
						if (coonnectedTo == m_spaceObjects[t]->getConnection() && orderOnConnected > m_spaceObjects[t]->getOrder())
						{
							newOrbitRadius = newOrbitRadius +  (m_spaceObjects[t]->getRadius() * 2) + 5;
							
							//projdi planety navazane na obihajici planetu
							for (size_t x = 0; x < m_spaceObjects.size(); x++)
							{
								if (m_spaceObjects[t].get() == m_spaceObjects[x]->getConnection())
								{
									newOrbitRadius = newOrbitRadius + (m_spaceObjects[x]->getRadius() * 5) + 10;
								}
							}
						}
					}

					if (k = orderOnConnected)
					{

						orbit* newOrbit = new orbit(coonnectedTo, newOrbitRadius, (i * 0.2) * 1.f, (k-i * 0.02) * 0.01f);
						//orbit* newOrbit = new orbit(coonnectedTo, newOrbitRadius, 0.15f, 0.01f);
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
