#ifndef FMODMANAGER_HPP_
# define FMODMANAGER_HPP_

/*!
 *  \author Geoffrey Hervet
 */

# include <map>
# include <vector>

# include <fmod.hpp>
# include <fmod_errors.h>

# include "ISoundManager.hpp"
# include "Error.hpp"

/*!
 * \brief FMODEx sound manager
 */
class			FmodManager
: public ISoundManager
{
  protected:
    static const int			MAX_CHANNELS = 32; /*!< Default number channels */
    static const unsigned char		DEFAULT_VOLUME = 75; /*!< Default volume */
    static const signed char		DEFAULT_PAN = 0; /*!< Default Pan */

  private:
    FmodManager(const FmodManager &);
    FmodManager const& operator =(const FmodManager &);

    void			        	thrower(const FMOD_RESULT &, Error::eLevel = Error::CRITICAL) const;
    void					addNewChann(::FMOD::Channel *);
  public:
    /*!
     * FMOD Constructor
     */
    FmodManager();

    virtual					~FmodManager();


    void					setFlag(ISoundManager::eFlag);
    void					unsetFlag(ISoundManager::eFlag);

    void					setVolume(unsigned char volume);
    void					setPan(signed char pan);

    unsigned char				getVolume(void) const { return  this->_volume; };
    signed char					getPan(void) const { return this->_pan; };

    void					unloadSound(char const * const fileName);
    void					unloadSound(const std::string &fileName);
    void					loadSound(char const * const fileName);
    void					loadSound(const std::string &fileName);

    void					playSound(char const * const fileName, signed char pan, unsigned char volume);
    void					playSound(const std::string &fileName, signed char pan, unsigned char volume);

  private:
    ::std::vector< ::FMOD::Channel *>		 _channel;/*!< Channels sound */
    ::FMOD::System				*_system; /*!< FMOD system */
    ::std::map<std::string, ::FMOD::Sound *>	 _sounds; /*!< Sounds which are loaded */
    ::FMOD::ChannelGroup			*_master; /*!< Master channel */
    std::vector<ISoundManager::eFlag>		 _flags;  /*!< Flags */
    signed char				 	 _pan;    /*!< Current pan */
    unsigned char				 _volume; /*!< Current volume */
};

#endif /* FMODMANAGER_HPP_ */
