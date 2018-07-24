#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

#include "World.h"

class Game
{
public:
    Game();
    void run();

private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
    void updateStatistics(sf::Time elapsedTime);

private:
    sf::RenderWindow mWindow;
    World mWorld;

    sf::Font mFont;
    sf::Text mStatisticsText;
    sf::Time mStatisticsUpdateTime;
    std::size_t mStatisticsNumFrames;
};

#endif // GAME_H
