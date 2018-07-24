#include "Application.h"
#include "Utility.h"
#include "TitleState.h"
#include "GameState.h"
#include "MenuState.h"
#include "PauseState.h"
#include "LoadingState.h"
#include "SettingsState.h"

#include <SFML/Graphics.hpp>

const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);

Application::Application() :
    mWindow(sf::VideoMode(640, 480), "World", sf::Style::Close),
    mTextures(),
    mFont(),
    mPlayer(),
    mStateStack(State::Context(mWindow, mTextures, mFonts, mPlayer)),
    mStatisticsText(),
    mStatisticsUpdateTime(),
    mStatisticsNumFrames(0)
{
    mWindow.setKeyRepeatEnabled(false);

    mFonts.load(Fonts::Main, "media/font/Sansation.ttf");
    mTextures.load(Textures::TitleScreen, "media/texture/TitleScreen.png");
    mTextures.load(Textures::ButtonNormal, "media/texture/ButtonNormal.png");
    mTextures.load(Textures::ButtonPressed, "media/texture/ButtonPressed.png");
    mTextures.load(Textures::ButtonSelected, "media/texture/ButtonSelected.png");

    mStatisticsText.setFont(mFont);
    mStatisticsText.setPosition(5.f, 5.f);
    mStatisticsText.setCharacterSize(10u);

    registerStates();
    mStateStack.pushState(States::Loading);
}

void Application::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while (mWindow.isOpen())
    {
        sf::Time elapsedTime = clock.restart();
        timeSinceLastUpdate += elapsedTime;
        while (timeSinceLastUpdate > TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;

            processInput();
            update(TimePerFrame);

            // Check inside this loop, because stack might be empty before update() call
            if (mStateStack.isEmpty())
                mWindow.close();
        }
        updateStatistics(elapsedTime);
        render();
    }
}

void Application::processInput()
{
    sf::Event event;
    while(mWindow.pollEvent(event))
    {
        mStateStack.handlEvent(event);

        if (event.type == sf::Event::Closed)
            mWindow.close();
    }
}

void Application::update(sf::Time deltaTime)
{
    mStateStack.update(deltaTime);
}

void Application::render()
{
    mWindow.clear();
    mStateStack.draw();

    mWindow.setView(mWindow.getDefaultView());
    mWindow.draw(mStatisticsText);

    mWindow.display();
}

void Application::updateStatistics(sf::Time elapsedTime)
{
    mStatisticsUpdateTime += elapsedTime;
    mStatisticsNumFrames += 1;

    if (mStatisticsUpdateTime >= sf::seconds(1.0f))
    {
        mStatisticsText.setString("FPS: " + toString(mStatisticsNumFrames));

        mStatisticsUpdateTime -= sf::seconds(1.0f);
        mStatisticsNumFrames = 0;
    }
}

void Application::registerStates()
{
    mStateStack.registerState<LoadingState>(States::Loading);
    mStateStack.registerState<TitleState>(States::Title);
    mStateStack.registerState<MenuState>(States::Menu);
    mStateStack.registerState<GameState>(States::Game);
    mStateStack.registerState<PauseState>(States::Pause);
    mStateStack.registerState<SettingsState>(States::Settings);
}




