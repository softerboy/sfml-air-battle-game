#ifndef __WORLD_H__
#define __WORLD_H__

#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"
#include "SceneNode.h"
#include "SpriteNode.h"
#include "Aircraft.h"
#include "CommandQueue.h"
#include "Command.h"
#include "BloomEffect.h"

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Shader.hpp>

#include <array>
#include <queue>


// Forward declaration
namespace sf
{
class RenderTarget;
}

class SoundPlayer;

class World : private sf::NonCopyable
{
public:
    explicit World(sf::RenderTarget& window, FontHolder& fonts, SoundPlayer &sounds);
    void update(sf::Time dt);
    void draw();

    CommandQueue& getCommandQueue();

    bool hasAlivePlayer() const;
    bool hasPlayerReachedEnd() const;


private:
    void loadTextures();
    void adaptPlayerPosition();
    void adaptPlayerVelocity();
    void handleCollisions();
    void updateSounds();

    void buildScene();
    void addEnemies();
    void addEnemy(Aircraft::Type type, float relX, float relY);
    void spawnEnemies();
    void destroyEntitiesOutsideView();
    void guideMissiles();
    sf::FloatRect getViewBounds() const;
    sf::FloatRect getBattlefieldBounds() const;


private:
    enum Layer
    {
        Background,
        LowerAir,
        UpperAir,
        LayerCount
    };

    struct SpawnPoint
    {
        SpawnPoint(Aircraft::Type type, float x, float y)
            : type(type)
            , x(x)
            , y(y)
        {
        }

        Aircraft::Type type;
        float x;
        float y;
    };


private:
    sf::RenderTarget& mTarget;
    sf::RenderTexture mSceneTexture;
    sf::View mWorldView;
    TextureHolder mTextures;
    FontHolder&	mFonts;
    SoundPlayer& mSounds;

    SceneNode mSceneGraph;
    std::array<SceneNode*, LayerCount> mSceneLayers;
    CommandQueue mCommandQueue;

    sf::FloatRect mWorldBounds;
    sf::Vector2f mSpawnPosition;
    float mScrollSpeed;
    Aircraft* mPlayerAircraft;

    std::vector<SpawnPoint>	mEnemySpawnPoints;
    std::vector<Aircraft*> mActiveEnemies;

    BloomEffect mBloomEffect;
};

#endif // __WORLD_H__
