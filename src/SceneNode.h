#ifndef SCENENODE_H
#define SCENENODE_H

#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Command.h"

class SceneNode : public sf::Transformable, public sf::Drawable,
        private sf::NonCopyable
{
public:
    typedef std::unique_ptr<SceneNode> Ptr;

public:
    SceneNode();

public:
    void attachChild(Ptr child);
    Ptr detachChild(const SceneNode& node);

public:
    void update(sf::Time dt);
    virtual unsigned int getCategory() const;
    void onCommand(const Command& command, sf::Time dt);

private:
    virtual void updateCurrent(sf::Time dt);
    void updateChildren(sf::Time dt);

private:
    sf::Transform getWorldTransform() const;
    sf::Vector2f getWorldPosition() const;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    std::vector<Ptr> mChildren;
    SceneNode* mParent;
};

#endif // SCENENODE_H
