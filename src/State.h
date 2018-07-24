#ifndef STATE_H
#define STATE_H

#include <memory>

#include <SFML/Graphics.hpp>

#include "StateIdentifiers.h"
#include "ResourceIdentifiers.h"

class StateStack;
class Player;

class State
{
public:
    typedef std::unique_ptr<State> Ptr;
    struct Context {
        Context(sf::RenderWindow& window,
                TextureHolder& textures,
                FontHolder& fonts,
                Player& player);

        sf::RenderWindow* window;
        TextureHolder* textures;
        FontHolder* fonts;
        Player* player;
    };

public:
    State(StateStack& stack, Context context);
    virtual ~State();

    virtual void draw() = 0;
    virtual bool update(sf::Time dt) = 0;
    virtual bool handleEvent(const sf::Event& event) = 0;

    Context getContext() const;

protected:
    void requestStackPush(States::ID stateID);
    void requestStackPop();
    void requestStackClear();

private:
    StateStack* mStack;
    Context mContext;
};

#endif // STATE_H
