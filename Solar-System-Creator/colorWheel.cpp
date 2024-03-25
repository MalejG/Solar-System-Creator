#include "colorWheel.h"

colorWheel::colorWheel()
{
	palety["star"] = { sf::Color(255, 255, 0), sf::Color(255, 105, 180), sf::Color(0, 191, 255) };
	palety["planet"] = { sf::Color(0, 0, 200), sf::Color(30, 144, 255), sf::Color(255, 69, 0) };
	index["star"] = 0;
	index["planet"] = 0;
}

sf::Color colorWheel::getColor(const string& objectType)
{

    auto& palette = palety[objectType];
    if (palette.empty()) return sf::Color::Black;

    auto& currentIndex = index[objectType];
    sf::Color color = palette[currentIndex];

    currentIndex = (currentIndex + 1) % palette.size();

    return color;
}
