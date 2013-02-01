/*!
 *  \author Geoffrey Hervet
 */

#ifndef ISOUNDMANAGER_HPP_
# define ISOUNDMANAGER_HPP_

# include		<string>

/*!
 * \brief Interface for sound hanler
 * \author Geoffrey HERVET
 * Interface for sound hanler
 */
class			  ISoundManager
{
  public:
    virtual			~ISoundManager(){};

    enum eFlag
    {
      NONE,
      LOOP
    };

    virtual void		setFlag(ISoundManager::eFlag) = 0;
    virtual void		unsetFlag(ISoundManager::eFlag) = 0;

    /*!
     * Play a sound in a specific channel
     * \param fileName File to play
     * \param pan Set a pan for sound
     * \param volume Volume of the sound in percent (0 -> 100)
     */
    virtual void		playSound(char const * const fileName, signed char pan = 0, unsigned char volume = 100) = 0;

    /*!
     * Play a sound in a specific channel
     * \param fileName File to play
     * \param pan Set a pan for sound
     * \param volume Volume of the sound in percent (0 -> 100)
     */
    virtual void		playSound(const std::string &fileName, signed char pan = 0, unsigned char volume = 100) = 0;

    /*!
     * Load a sound in memory
     * \param fileName path to file 
     */
    virtual void		loadSound(char const * const fileName) = 0;

    /*!
     * Load a sound in memory
     * \param fileName path to file 
     */
    virtual void		loadSound(const std::string &fileName) = 0;

    /*!
     * unload a sound in memory
     * \param fileName path to file 
     */
    virtual void		unloadSound(char const * const fileName) = 0;

    /*!
     * unload a sound in memory
     * \param fileName path to file 
     */
    virtual void		unloadSound(const std::string &fileName) = 0;

    /*!
     * Set default volume in channel
     * \param volume Volume in percentage 0->100
     */
    virtual void		setVolume(unsigned char volume) = 0;

    /*!
     * Volume getter
     * \return Volume between 0 and 100
     */
    virtual unsigned char	getVolume(void) const = 0;

    /*!
     * Set pan
     * \param pan value of new pan between -100 & 100
     */
    virtual void		setPan(signed char pan) = 0;

    /*!
     * Pan getter
     * \return Value of pas between -100 & 100
     */
    virtual signed char	getPan(void) const = 0;
};

#endif
