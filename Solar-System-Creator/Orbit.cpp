
#include "orbit.h"

#include <iostream>

using namespace std;

orbit::orbit(spaceObject* spaceObject, float radius, float angle, float speed)
    : m_parent { spaceObject }
    , m_radius { radius }
    , m_angle { angle }
    , m_speed { speed }
{
    cout << __FUNCTION__ << "\n";

}

void orbit::update()
{
    m_angle += m_speed;
    if (m_angle >= 360.0f)
    {
        m_angle -= 360.0f;
    }
}

sf::Vector2f orbit::getPosition() const
{
    if (!m_parent) return { 0, 0 };

    sf::Vector2f center = m_parent->getPosition();
    float x = center.x + cos(m_angle * 3.14159f / 180.0f) * m_radius;
    float y = center.y + sin(m_angle * 3.14159f / 180.0f) * m_radius;
    return { x ,y };
}
;