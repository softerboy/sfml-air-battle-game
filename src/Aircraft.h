#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include "Entity.h"
#include "ResourceIdentifiers.h"

class Aircraft : public Entity
{
public:
    enum Type {
        Eagle,
        Raptor
    };

public:
    explicit Aircraft(Type type, const TextureHolder& textures);

public:
    virtual unsigned int getCategory() const;
    void accelerate(sf::Vector2f v);
    void accelerate(float vx, float vy);

private:
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    Type mType;
    sf::Sprite mSprite;
};

#endif // AIRCRAFT_H
