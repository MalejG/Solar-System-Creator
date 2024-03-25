#pragma once

#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>




using namespace std;

class colorWheel
{
public:
	colorWheel();
	sf::Color getColor(const string & objectType);

private:
	map<string, vector<sf::Color>> palety;
	map<string, size_t> index;
};