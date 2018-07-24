#include "Aircraft.h"
#include "Category.h"

Textures::ID toTextureID(Aircraft::Type type) {
    switch (type) {
    case Aircraft::Eagle:
        return Textures::Eagle;
    case Aircraft::Raptor:
        return Textures::Raptor;
    default:
        return Textures::Desert;
    }
}

Aircraft::Aircraft(Aircraft::Type type, const TextureHolder &textures)
    : mType(type), mSprite(textures.get(toTextureID(type)))
{
    sf::FloatRect bounds = mSprite.getLocalBounds();
    mSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

unsigned int Aircraft::getCategory() const
{
    switch (mType) {
    case Eagle:
        return Category::PlayerAircraft;
    default:
        return Category::EnemyAircraft;
    }
}

void Aircraft::accelerate(sf::Vector2f v)
{
    setVelocity(getVelocity() + v);
}

void Aircraft::accelerate(float vx, float vy)
{
    setVelocity(getVelocity().x + vx, getVelocity().y + vy);
}

void Aircraft::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(mSprite, states);
}
