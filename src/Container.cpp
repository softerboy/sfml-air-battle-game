#include "Container.h"

namespace GUI {

Container::Container() :
    mChildren(),
    mSelectedChild(-1)
{}

void Container::pack(Component::Ptr component)
{
    mChildren.push_back(component);

    if (!hasSelection() && component->isSelectable())
        select(mChildren.size() - 1);
}

bool Container::isSelectable() const
{
    return false;
}

void Container::handleEvent(const sf::Event &event)
{
    // if we have selected a child then give it events
    if (hasSelection() && mChildren[mSelectedChild]->isActive())
        mChildren[mSelectedChild]->handleEvent(event);
    else if(event.type == sf::Event::KeyReleased)
    {
        if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up)
            selectPrevious();
        else if(event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down)
            selectNext();
        else if(event.key.code == sf::Keyboard::Return || event.key.code == sf::Keyboard::Space)
            if(hasSelection())
                mChildren[mSelectedChild]->activate();
    }
}

void Container::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    for (const auto& child : mChildren)
        target.draw(*child, states);
}

bool Container::hasSelection() const
{
    return mSelectedChild >= 0;
}

void Container::select(std::size_t index)
{
    if (mChildren[index]->isSelectable())
    {
        if (hasSelection())
            mChildren[mSelectedChild]->deselect();

        mChildren[index]->select();
        mSelectedChild = index;
    }
}

void Container::selectNext()
{
    if (!hasSelection())
        return;

    // search next component that is selectable, wrap around if necessary
    int next = mSelectedChild;
    do
        next = (next + 1) % mChildren.size();
    while(!mChildren[next]->isSelectable());

    // select that component
    select(next);
}

void Container::selectPrevious()
{
    if (!hasSelection())
        return;

    // search previous component that is selectable, wrap around if necessary
    int previous = mSelectedChild;
    do
        previous = (previous + mChildren.size() - 1) % mChildren.size();
    while(!mChildren[previous]->isSelectable());

    // select that component
    select(previous);
}

}
