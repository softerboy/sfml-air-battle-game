#ifndef __UTILITY_H__
#define __UTILITY_H__

#include <sstream>

#include <SFML/Window/Keyboard.hpp>

namespace sf
{
class Sprite;
class Text;
}

// Since std::to_string doesn't work on MinGW we have to implement
// our own to support all platforms.
template <typename T>
std::string toString(const T& value);

// Convert enumerators to strings
std::string toString(sf::Keyboard::Key key);

void centerOrigin(sf::Sprite& sprite);
void centerOrigin(sf::Text& text);

#include "Utility.inl"

#endif // __UTILITY_H__
