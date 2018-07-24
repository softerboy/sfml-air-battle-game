#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

#include "CommandQueue.h"

class Player
{
public:
    Player();

public:
    void handleEvent(const sf::Event& event, CommandQueue& commands);
    void handleRealtimeInput(CommandQueue& commands);

public:
    enum Action { MoveLeft, MoveRight, MoveUp, MoveDown, ActionCount };

    void assignKey(Action action, sf::Keyboard::Key key);
    sf::Keyboard::Key getAssignedKey(Action action) const;

private:
    static bool isRealtimeAction(Action action);
    void initializeActions();

private:
    std::map<sf::Keyboard::Key, Action> mKeyBinding;
    std::map<Action, Command> mActionBinding;
};

#endif // PLAYER_H
