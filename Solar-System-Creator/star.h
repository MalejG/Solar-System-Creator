#pragma once

#include "spaceObject.h"

#include <set>

class star : public spaceObject
{
public:
	star();
	 ~star();
	star(const float& radius);

	float getRadius() const override;
	spaceObject* getConnection() const override;

	void setRadius(const float& radius) override;
	void setConnection(spaceObject* connectedTo) override;

	virtual void draw(sf::RenderWindow& window) override;


	void call() override;

private:
	float m_radius;
};