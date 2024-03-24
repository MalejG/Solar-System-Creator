#pragma once
#include "spaceObject.h"

class spaceObject;

class orbit
{
public:
	orbit(spaceObject* spaceObject, float radius, float angle, float speed);

	void update();
	sf::Vector2f getPosition() const;

private:
	spaceObject* m_parent;
	float m_radius;
	float m_angle;
	float m_speed;
};

