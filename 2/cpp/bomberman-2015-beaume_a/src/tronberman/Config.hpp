#ifndef	        CONFIG_HPP_
# define	CONFIG_HPP_

/*!
 *  \file       BombermanConfig.hpp
 *  \brief      Here are the configurations const var for this project
 *  \author     Aymeric Beaumet
 */

#include	<string>

/*!
 *  \class      Config
 *  \brief      Configurations const var for this project are in this namespace
 *  \author     Aymeric Beaumet
 */
class Config
{
  public:
    static std::string const DefaultConfigurationFile;
    static std::string const DefaultLogFile;

    static std::string const DefaultMapExtension;
    static std::string const DefaultBackupExtension;

    static std::string const MapDirectory;
    static std::string const BackupsDirectory;
};

#endif /* !CONFIG_HPP_ */
