#include "SoundPlayer.h"

SoundPlayer::SoundPlayer()
    : mSoundBuffers()
    , mSounds()
{
    mSoundBuffers.load(SoundEffect::AlliedGunfire, "media/sound/AlliedGunfire.wav");
    mSoundBuffers.load(SoundEffect::EnemyGunfire, "media/sound/EnemyGunfire.wav");
    mSoundBuffers.load(SoundEffect::Explosion1, "media/sound/Explosion1.wav");
    mSoundBuffers.load(SoundEffect::Explosion2, "media/sound/Explosion2.wav");
    mSoundBuffers.load(SoundEffect::LaunchMissile, "media/sound/LaunchMissile.wav");
    mSoundBuffers.load(SoundEffect::CollectPickup, "media/sound/CollectPickup.wav");
    mSoundBuffers.load(SoundEffect::Button, "media/sound/Button.wav");
}

void SoundPlayer::play(SoundEffect::ID effect)
{
    mSounds.push_back(sf::Sound(mSoundBuffers.get(effect)));
    mSounds.back().play();
}

void SoundPlayer::removeStoppedSounds()
{
    mSounds.remove_if([] (const sf::Sound& s) {
        return s.getStatus() == sf::Sound::Stopped;
    });
}
