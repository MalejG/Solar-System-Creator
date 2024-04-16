#pragma once

#include <SFML/Graphics.hpp>

#include "colorWheel.h"

#include "orbit.h"

class orbit;
class colorWheel;
class radiusWheel;

class spaceObject
{
public:
	spaceObject();
	virtual ~spaceObject();

	//get
	virtual float getRadius() const = 0;
	virtual spaceObject* getConnection() const = 0;
	
	//set
	virtual void setRadius(const float& radius) = 0;
	virtual int setOrder(const float& order) = 0;
	//virtual void setOrbit(orbit orbit) = 0;
	virtual void setConnection(spaceObject* connectedTo) = 0;
	virtual void setColorWheel() = 0;

	//draw
	virtual void draw(sf::RenderWindow& window) = 0;

	//orbit
	virtual void update() = 0;
	virtual sf::Vector2f getPosition() const = 0;

private:
};