#pragma once

#include "spaceObject.h"

#include <set>

class star : public spaceObject
{
public:
	star();
	 ~star();
	star(const int& radius);

	int getRadius() const override;
	spaceObject* getConnection() const override;

	void setRadius(const int& radius) override;
	void setConnection(spaceObject* connectedTo) override;

	void call() override;

private:
	int m_radius;
};