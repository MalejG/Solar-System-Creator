#pragma once

#include "spaceObject.h"

#include <vector>
#include <memory>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

using spaceObjPtr = std::shared_ptr<spaceObject>;

class background 
{
public:
	background();
	void add(spaceObjPtr utvar);
	void update();
	void draws(sf::RenderWindow &window);
	void getSpaceObjPtrVec();
	void dynamicOrbit();

	void searchOrder();
private:
	std::vector<spaceObjPtr> m_spaceObjects;
	size_t m_pickedSpaceObject;
};
