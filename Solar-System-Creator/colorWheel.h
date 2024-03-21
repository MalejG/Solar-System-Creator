#pragma once

#include <vector>
#include <map>
#include <iostream>
#include <string>

using namespace std;

class colorWheel
{
public:
	colorWheel();
	//getColor();
	//unsigned next();
private:
	map<string, vector<unsigned>> palettes;

};