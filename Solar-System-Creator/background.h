#pragma once

#include "spaceObject.h"

#include <vector>
#include <memory>
#include <iostream>

using spaceObjPtr = std::unique_ptr<spaceObject>;

class background 
{
public:
	
private:
 
	std::vector<spaceObjPtr> m_spaceObjects;
};
