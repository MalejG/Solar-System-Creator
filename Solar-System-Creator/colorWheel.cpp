#include "colorWheel.h"

colorWheel::colorWheel()
{
	palety["star"] = 
    { 
        sf::Color(255, 255, 0), 
        sf::Color(255, 105, 180), 
        sf::Color(0, 191, 255) 
    };
	
    palety["planet"] = 
    { 
        sf::Color(76, 153, 0),
        sf::Color(64, 64, 64),
        sf::Color(0, 102, 102),
        sf::Color(0, 102, 54),
        sf::Color(0, 204, 102)
    };
	
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
