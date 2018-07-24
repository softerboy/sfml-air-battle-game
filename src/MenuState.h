#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "State.h"
#include "Container.h"

class StateStack;

class MenuState : public State
{
public:
    MenuState(StateStack& stack, Context context);

    virtual void draw();
    virtual bool update(sf::Time dt);
    virtual bool handleEvent(const sf::Event& event);

private:
    sf::Sprite mBackgroundSprite;
    GUI::Container mGUIContainer;
};
#endif // MENUSTATE_H
