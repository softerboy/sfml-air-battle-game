#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"
#include "World.h"

class StateStack;
class Player;

class GameState : public State
{
public:
    GameState(StateStack& stack, Context context);

    virtual void draw();
    virtual bool update(sf::Time dt);
    virtual bool handleEvent(const sf::Event &event);

private:
    World mWorld;
    Player& mPlayer;
};

#endif // GAMESTATE_H
