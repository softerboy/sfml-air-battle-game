#include "StateStack.h"

#include <cassert>

StateStack::StateStack(State::Context context)
    : mStack(),
      mPendingList(),
      mContext(context),
      mFactories() {}

void StateStack::update(sf::Time dt)
{
    // Iterate from top to bottom, stop as soon as update() returns false
    for (auto itr = mStack.rbegin(); itr != mStack.rend(); ++itr)
    {
        if (!(*itr)->update(dt))
            break;
    }

    applyPendingChanges();
}

void StateStack::draw()
{
    for(auto& state : mStack)
        state->draw();
}

void StateStack::handlEvent(const sf::Event &event)
{
    for (auto itr = mStack.rbegin(); itr != mStack.rend(); itr++)
        if(!(*itr)->handleEvent(event))
            return;

    applyPendingChanges();
}

void StateStack::pushState(States::ID stateID)
{
    mPendingList.push_back(PendingChange(Push, stateID));
}

void StateStack::popState()
{
    mPendingList.push_back(PendingChange(Pop));
}

void StateStack::clearStates()
{
    mPendingList.push_back(PendingChange(Clear));
}

bool StateStack::isEmpty() const
{
    return mStack.empty();
}

State::Ptr StateStack::createState(States::ID stateID)
{
    auto found = mFactories.find(stateID);
    assert(found != mFactories.end());

    return found->second();
}

void StateStack::applyPendingChanges()
{
    for (auto change : mPendingList){
        switch (change.action) {
        case Push:
            mStack.push_back(createState(change.stateID));
            break;

        case Pop:
            mStack.pop_back();
            break;

        case Clear:
            mStack.clear();
            break;
        }
    }

    mPendingList.clear();
}

StateStack::PendingChange::PendingChange(StateStack::Action action, States::ID stateID)
    : action(action),
      stateID(stateID)
{}
