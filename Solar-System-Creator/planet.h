#pragma once

#include "spaceObject.h"

#include <set>

class planet : public spaceObject
{
public:
	using spaceObject::spaceObject;

	planet();
	 ~planet();
	planet(const int& radius, spaceObject& connected);

	int getRadius() const override;
	spaceObject* getConnection() const override;

	void setRadius(const int& radius) override;
	void setConnection(spaceObject* connectedTo) override;

	void call() override;
private:
	int m_radius;
	std::set<spaceObject*> m_connectedTo;
};