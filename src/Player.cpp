#include "Player.h"
#include "Aircraft.h"
#include "Category.h"

#include <iostream>

struct AircraftMover
{
    AircraftMover(float vx, float vy) : velocity(vx, vy) { }

    void operator () (Aircraft& aircraft, sf::Time) const {
        aircraft.accelerate(velocity);
    }

private:
    sf::Vector2f velocity;
};

Player::Player()
{
    mKeyBinding[sf::Keyboard::Left] = MoveLeft;
    mKeyBinding[sf::Keyboard::Right] = MoveRight;
    mKeyBinding[sf::Keyboard::Up] = MoveUp;
    mKeyBinding[sf::Keyboard::Down] = MoveDown;

    initializeActions();

    for (auto& pair : mActionBinding)
        pair.second.category = Category::PlayerAircraft;
}

void Player::handleEvent(const sf::Event &event, CommandQueue &commands)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P)
    {
        Command output;
        output.category = Category::PlayerAircraft;
        output.action = [] (SceneNode& s, sf::Time)
        {
            std::cout << s.getPosition().x << ","
                      << s.getPosition().y << "\n";
        };
        commands.push(output);
    }
}

void Player::handleRealtimeInput(CommandQueue &commands)
{
    for (auto pair : mKeyBinding)
        if (sf::Keyboard::isKeyPressed(pair.first) && isRealtimeAction(pair.second))
            commands.push(mActionBinding[pair.second]);
}

void Player::assignKey(Player::Action action, sf::Keyboard::Key key)
{
    // Remove all keys that already map to action
    for (auto itr = mKeyBinding.begin(); itr != mKeyBinding.end(); )
    {
        if (itr->second == action)
            mKeyBinding.erase(itr++);
        else
            ++itr;
    }

    // Insert new binding
    mKeyBinding[key] = action;
}

sf::Keyboard::Key Player::getAssignedKey(Player::Action action) const
{
    for(auto pair : mKeyBinding) {
        if (pair.second == action)
            return pair.first;
    }

    return sf::Keyboard::Unknown;
}

void Player::initializeActions()
{
    const float playerSpeed = 200.f;

    mActionBinding[MoveLeft].action	 = derivedAction<Aircraft>(AircraftMover(-playerSpeed, 0.f));
    mActionBinding[MoveRight].action = derivedAction<Aircraft>(AircraftMover(+playerSpeed, 0.f));
    mActionBinding[MoveUp].action    = derivedAction<Aircraft>(AircraftMover(0.f, -playerSpeed));
    mActionBinding[MoveDown].action  = derivedAction<Aircraft>(AircraftMover(0.f, +playerSpeed));
}

bool Player::isRealtimeAction(Player::Action action)
{
    switch (action)
    {
    case MoveLeft:
    case MoveRight:
    case MoveDown:
    case MoveUp:
        return true;

    default:
        return false;
    }
}
