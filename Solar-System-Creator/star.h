#pragma once

#include "spaceObject.h"

#include <set>

class star : public spaceObject
{
public:
	star();
	 ~star();
	star(const float& radius);

	//get
	float getRadius() const override;
	int getOrder() const override;
	spaceObject* getConnection() const override;

	//set
	void setRadius(const float& radius) override;
	void setOrder(const int& order) override;
	void setOrbit(orbit* newOrbit) override;
	void setConnection(spaceObject* connectedTo) override;
	void setColorWheel() override;

	virtual void draw(sf::RenderWindow& window) override;
	virtual void drawOutline(sf::RenderWindow& window) override;

	sf::Vector2f getPosition() const;
	void update()  {};

private:
	float m_radius;
};