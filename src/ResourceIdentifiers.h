#ifndef __RESOURCE_IDENTIFIERS_H__
#define __RESOURCE_IDENTIFIERS_H__

#include "ResourceHolder.h"

// Forward declaration of SFML classes
namespace sf
{
    class Texture;
    class Font;
}

namespace Textures
{
    enum ID
    {
        Eagle,
        Raptor,
        Desert,
        TitleScreen,
        ButtonNormal,
        ButtonSelected,
        ButtonPressed
    };
}

namespace Fonts {
    enum ID { Main };
}

// Forward declaration and a few type definitions
template <typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;

typedef ResourceHolder<sf::Font, Fonts::ID> FontHolder;

#endif // __RESOURCE_IDENTIFIERS_H__
