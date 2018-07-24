#ifndef __RESOURCE_IDENTIFIERS_H__
#define __RESOURCE_IDENTIFIERS_H__

#include "ResourceHolder.h"

// Forward declaration of SFML classes
namespace sf
{
    class Texture;
}

namespace Textures
{
    enum ID
    {
        Eagle,
        Raptor,
        Desert,
    };
}

// Forward declaration and a few type definitions
template <typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;

#endif // __RESOURCE_IDENTIFIERS_H__
