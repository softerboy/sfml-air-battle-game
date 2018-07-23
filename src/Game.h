#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

#include "TextureHolder.h"

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

private:
    sf::RenderWindow mWindow;
    sf::Sprite mPlayer;
    sf::Texture mTexture;
    Textureholder mTextureHolder;

private:
    bool mIsMovingUp;
    bool mIsMovingDown;
    bool mIsMovingLeft;
    bool mIsMovingRight;
};

#endif // GAME_H
