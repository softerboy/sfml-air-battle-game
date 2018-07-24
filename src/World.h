#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>

#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"
#include "SceneNode.h"
#include "Aircraft.h"
#include "CommandQueue.h"

#include <array>

class World : private sf::NonCopyable
{
public:
    explicit World(sf::RenderWindow& window);
    void update(sf::Time dt);
    void draw();
    CommandQueue& getCommandQueue();

private:
    void loadTextures();
    void buildScene();

private:
    enum Layer { Background, Air, LayerCount };

private:
    void adaptPlayerPosition();
    void adaptPlayerVelocity();

private:
    sf::RenderWindow& mWindow;
    sf::View mWorldView;
    TextureHolder mTextures;

    SceneNode mSceneGraph;
    std::array<SceneNode*, LayerCount> mSceneLayers;
    CommandQueue mCommandQueue;

    sf::FloatRect mWorldBounds;
    sf::Vector2f mSpawnPosition;
    float mScrollSpeed;
    Aircraft* mPlayerAircraft;
};

#endif // WORLD_H
