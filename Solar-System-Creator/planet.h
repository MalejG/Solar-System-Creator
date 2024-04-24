#pragma once

#include "spaceObject.h"
#include "colorWheel.h"
#include <set>

class planet : public spaceObject
{
public:
	using spaceObject::spaceObject;

	planet();
	 ~planet();
	planet(const float& radius, spaceObject& connected, int order, float orbitRadius, float orbitAngle, float orbitSpeed);

	//get
	float getRadius() const override;
	int getOrder() const override;
	spaceObject* getConnection() const override;
	sf::Vector2f getPosition() const;

	//set
	void setOrder(const int& order) override;
	void setOrbit(orbit* newOrbit) override;
	void setRadius(const float& radius) override;
	void setConnection(spaceObject* connectedTo) override;
	void setColorWheel() override;


	virtual void draw(sf::RenderWindow& window) override;
	virtual void drawOutline(sf::RenderWindow& window)  override;

	void update() override;

private:
	float m_radius;
	std::set<spaceObject*> m_connectedTo;
	orbit* m_orbit;
	static colorWheel m_wheel;
	sf::Color m_color;
	int m_order;
};