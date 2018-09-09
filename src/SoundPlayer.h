#ifndef SOUNDPLAYER_H
#define SOUNDPLAYER_H

#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"

#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

#include <list>

class SoundPlayer : sf::NonCopyable
{
public:
    SoundPlayer();

    void play(SoundEffect::ID effect);
    void play(SoundEffect::ID effect, sf::Vector2f position);

    void removeStoppedSounds();
    void setListenerPosition(sf::Vector2f position);
    sf::Vector2f getListenerPosition() const;

private:
    SoundBufferHolder mSoundBuffers;
    std::list<sf::Sound> mSounds;
};

#endif // SOUNDPLAYER_H
