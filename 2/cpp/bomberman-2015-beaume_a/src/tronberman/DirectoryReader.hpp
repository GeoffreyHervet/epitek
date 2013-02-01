#ifndef DIRECTORYREADER_HPP_
# define DIRECTORYREADER_HPP_

# include	<sys/stat.h>
# include	<sys/types.h>
# include	<dirent.h>
# include	<string>
# include	<list>

# include	"Config.hpp"

class		DirectoryReader
{
  private:
    DirectoryReader();
    ~DirectoryReader();
    DirectoryReader(const DirectoryReader &);
    DirectoryReader &operator=(const DirectoryReader &);
  public:
    static std::list<std::string>	getMaps(const std::string & = Config::MapDirectory,
        const std::string & = Config::DefaultMapExtension);
    static std::list<std::string>	getBackups(const std::string & = Config::BackupsDirectory,
        const std::string & = Config::DefaultBackupExtension);
  private:
    static std::list<std::string>	getDir(std::string const& dir, std::string const& ext);
};

#endif /* DIRECTORYREADER_HPP_ */
