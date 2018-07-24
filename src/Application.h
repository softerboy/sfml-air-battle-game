#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include <SFML/Graphics.hpp>

#include "Player.h"
#include "World.h"
#include "StateStack.h"
#include "ResourceIdentifiers.h"

class Application
{
public:
    Application();
    void run();

private:
    void processInput();
    void update(sf::Time deltaTime);
    void render();

    void updateStatistics(sf::Time elapsedTime);
    void registerStates();

private:
    sf::RenderWindow mWindow;    
    TextureHolder mTextures;
    FontHolder mFonts;
    Player mPlayer;

    StateStack mStateStack;

    sf::Font mFont;
    sf::Text mStatisticsText;
    sf::Time mStatisticsUpdateTime;
    std::size_t mStatisticsNumFrames;
};

#endif // __APPLICATION_H__
