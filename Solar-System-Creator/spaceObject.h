#pragma once

#include <SFML/Graphics.hpp>

class colorWheel;
class radiusWheel;

class spaceObject
{
public:
	spaceObject();
	virtual ~spaceObject();

	virtual float getRadius() const = 0;
	virtual spaceObject* getConnection() const = 0;
	
	virtual void setRadius(const float& radius) = 0;
	virtual void setConnection(spaceObject* connectedTo) = 0;
	
	virtual void draw(sf::RenderWindow& window) = 0;

	virtual void call() = 0;
private:
	//static colorWheel m_colorWheel;
};