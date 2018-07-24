#ifndef __UTILITY_H__
#define __UTILITY_H__

#include <sstream>

namespace sf
{
class Sprite;
class Text;
}

// Since std::to_string doesn't work on MinGW we have to implement
// our own to support all platforms.
template <typename T>
std::string toString(const T& value);

void centerOrigin(sf::Sprite& sprite);
void centerOrigin(sf::Text& text);

#include "Utility.inl"

#endif // __UTILITY_H__
