#include <iostream>
#include <sstream>
#include <algorithm>

#include "FmodManager.hpp"
#include "Error.hpp"

#define E(X,Y) (this->thrower((X),(Y)))
#define EC(X)  (this->thrower((X), Error::CRITICAL))
#define EW(X)  (this->thrower((X), Error::WARN))

static void		freeSound(std::pair<std::string, ::FMOD::Sound *> i)
{
  i.second->release();
}

static void		freeChann(::FMOD::Channel *c)
{
  bool			isPlaying = true;

  if (c && FMOD_OK == c->isPlaying(&isPlaying) && !isPlaying)
    c->stop();
}

void			FmodManager::thrower(const FMOD_RESULT &r, Error::eLevel lvl) const
{
  if (r != FMOD_OK)
  {
    std::stringstream	ss;

    ss << "[Sound] " << FMOD_ErrorString(r);
    throw Error(ss.str().c_str(), lvl);
  }
}

  FmodManager::FmodManager()
: _channel(FmodManager::MAX_CHANNELS)
{
  unsigned int	version;
  // System init
  EC( ::FMOD::System_Create(&this->_system) );

  // Version
  EC(  this->_system->getVersion(&version) );

  if (version < FMOD_VERSION)
  {
    std::stringstream	ss;

    ss << "[FMOD] You're using an old version of FMOD (#" << version << "). This program requires version #" << FMOD_VERSION;
    throw Error(ss.str().c_str(), Error::CRITICAL);
  }

  EC(  this->_system->init(FmodManager::MAX_CHANNELS, FMOD_INIT_NORMAL, 0)  );

  EC(  this->_system->getMasterChannelGroup(&this->_master)   );
  this->setVolume(FmodManager::DEFAULT_VOLUME);
  this->setPan(FmodManager::DEFAULT_PAN);
}

FmodManager::~FmodManager()
{
  std::for_each(this->_sounds.begin(), this->_sounds.end(), freeSound);
  this->_system->close();
  this->_system->release();
}

void		FmodManager::unloadSound(char const * const fileName)
{
  this->unloadSound(std::string(fileName));
}

void		FmodManager::unloadSound(const std::string &fileName)
{
  if (this->_sounds[fileName])
  {
    E(  this->_sounds[fileName]->release(), Error::WARN);
    this->_sounds.erase(fileName);
  }
}

void		FmodManager::loadSound(char const * const fileName)
{
  this->loadSound(std::string(fileName));
}

void		FmodManager::loadSound(const std::string &fileName)
{
  if (!this->_sounds[fileName])
  {
    ::FMOD::Sound	*sound;
    if ( std::count(this->_flags.begin(), this->_flags.end(), ISoundManager::LOOP))
      EW(   this->_system->createSound(fileName.c_str(), FMOD_LOOP_NORMAL, 0, &sound)  );
    else
      EW(   this->_system->createSound(fileName.c_str(), FMOD_LOOP_OFF, 0, &sound)  );
    this->_sounds[fileName] = sound;
  }
}

void		FmodManager::setVolume(unsigned char volume)
{
  EC(   this->_master->setVolume(float(volume) / 100)  );
  this->_volume = volume;
  this->_system->update();
}

void		FmodManager::setPan(signed char pan)
{
  EC(   this->_master->overridePan(float(pan) / 100)  );
  this->_pan = pan;
  this->_system->update();
}

void		FmodManager::playSound(char const * const fileName, signed char pan, unsigned char volume)
{
  this->playSound(std::string(fileName), pan, volume);
}

void		FmodManager::playSound(const std::string &fileName, signed char pan, unsigned char volume)
{
  ::FMOD::Channel	*chan;

  //free unused chann
  for_each(this->_channel.begin(), this->_channel.end(), freeChann);
  this->loadSound(fileName);
  EW(  this->_system->playSound(FMOD_CHANNEL_REUSE, this->_sounds[fileName], true, &chan) );
  this->addNewChann(chan);

  // Pan
  /*!
   * \todo Tester si ca marche sinon, faut update partout pour le pan
   */
  EW(  chan->setPan(float(pan) / 100)  );
  this->setPan(this->getPan());
  /*
     if (!this->getPan())
     SoundPan = float(pan) / 100;
     else if (!pan)
     SoundPan = float(this->getPan()) / 100;
     else
     SoundPan = (this->getPan() + pan) % 1;
     */
  (void)volume;
  EW(  chan->setVolume(float(volume) / 100)  );
  EW(  chan->setPaused(false)   );
}

void		FmodManager::addNewChann(::FMOD::Channel *c)
{
  if (this->_channel.end() == std::find(this->_channel.begin(), this->_channel.end(), c))
  {
    int i = this->_channel.size();
    while (i-- >= 0)
    {
      if (!this->_channel[i])
      {
        this->_channel[i] = c;
        return;
      }
    }
    this->_channel.push_back(c);
  }
}

void		FmodManager::setFlag(ISoundManager::eFlag flag)
{
  if (! std::count(this->_flags.begin(), this->_flags.end(), flag))
    this->_flags.push_back(flag);
}

void		FmodManager::unsetFlag(ISoundManager::eFlag flag)
{
  for (unsigned int i = 0; this->_flags.size() && i < this->_flags.size(); i++)
    if (this->_flags[i] == flag)
      this->_flags.erase(this->_flags.begin() + i--);
  //std::remove(this->_flags.begin(), this->_flags.end(), flag);
}
