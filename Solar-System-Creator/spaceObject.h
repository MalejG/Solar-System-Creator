#pragma once


class colorWheel;
class radiusWheel;

class spaceObject
{
public:
	spaceObject();
	virtual ~spaceObject();

	virtual int getRadius() const = 0;
	virtual spaceObject* getConnection() const = 0;
	
	virtual void setRadius(const int &radius) = 0;
	virtual void setConnection(spaceObject* connectedTo) = 0;
	virtual void call() = 0;
private:
	//static colorWheel m_colorWheel;
};