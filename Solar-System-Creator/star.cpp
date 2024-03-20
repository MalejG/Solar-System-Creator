#include "star.h"
#include <iostream>

using namespace std;

star::star()
{
	cout << __FUNCTION__ << "\n";
}

star::~star()
{
	cout << __FUNCTION__ << "\n";
}

void star::call()
{
	cout << "\nim star";
}
