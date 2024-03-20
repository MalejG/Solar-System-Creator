#pragma once

#include "spaceObject.h"

class star : public spaceObject
{
public:
	star();
	~star();
	void call() override;
private:

};