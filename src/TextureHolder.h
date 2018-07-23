#ifndef __TEXTURE_HOLDER__
#define __TEXTURE_HOLDER__

#include <SFML/Graphics.hpp>

#include <map>
#include <memory>

namespace Textures {
    enum ID { Landscape, Airplane, Missile };
}

class Textureholder
{
private:
    std::map<Textures::ID, std::unique_ptr<sf::Texture>> mTextureMap;

public:
   void load(Textures::ID id, const std::string& filename);
   sf::Texture& get(Textures::ID id);
   const sf::Texture& get(Textures::ID id) const;

};

#endif __TEXTURE_HOLDER__
