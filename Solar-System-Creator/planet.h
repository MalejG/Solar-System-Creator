#pragma once

#include "spaceObject.h"

#include <set>

class planet : public spaceObject
{
public:
	using spaceObject::spaceObject;

	planet();
	 ~planet();
	planet(const float& radius, spaceObject& connected);

	float getRadius() const override;
	spaceObject* getConnection() const override;

	void setRadius(const float& radius) override;
	void setConnection(spaceObject* connectedTo) override;

	virtual void draw(sf::RenderWindow& window) override;

	void call() override;
private:
	float m_radius;
	std::set<spaceObject*> m_connectedTo;
};