#ifndef LOADINGSTATE_H
#define LOADINGSTATE_H

#include "State.h"
#include "ParallelTask.h"

class LoadingState : public State
{
public:
    LoadingState(StateStack& stack, Context context);

    virtual void draw();
    virtual bool update(sf::Time dt);
    virtual bool handleEvent(const sf::Event &event);

    void setCompletion(float percent);

private:
    sf::Text mLoadingText;
    sf::RectangleShape mProgressBarBackground;
    sf::RectangleShape mProgressBar;

    ParallelTask mLoadingTask;
};

#endif // LOADINGSTATE_H
