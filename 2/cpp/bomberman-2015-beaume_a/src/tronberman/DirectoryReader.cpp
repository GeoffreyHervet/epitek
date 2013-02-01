#include	<string>
#include	<sstream>
#include	<algorithm>

#include	"Error.hpp"
#include	"DirectoryReader.hpp"

std::list<std::string>	DirectoryReader::getDir(std::string const& dir, std::string const& ext)
{
  std::list<std::string>	files;
  struct dirent   		*ent;
  struct stat     		sts;
  DIR             		*rep = opendir(dir.c_str());
  std::string			fileName;

  if (rep == NULL)
    throw Error("Impossible to list directory", Error::WARN);
  while ((ent = readdir(rep)))
  {
    fileName.assign(ent->d_name);
    //check for the file extension
    if (fileName.size() < ext.size() ||
        fileName.compare(fileName.size() - ext.size(), ext.size(), ext) != 0)
      continue;
    std::stringstream ss("");
    ss << dir << "/" << fileName;
    if (stat(ss.str().c_str(), &sts) == -1)
      continue;
    //push the file without the extension
    if (!S_ISDIR(sts.st_mode))
      files.push_back(fileName.substr(0, fileName.size() - ext.size()));
  }
  closedir(rep);
  files.sort();
  return files;
}

std::list<std::string>	DirectoryReader::getMaps(const std::string &dir, std::string const& ext)
{
  return (getDir(dir, ext));
}

std::list<std::string>	DirectoryReader::getBackups(const std::string &dir, std::string const& ext)
{
  return (getDir(dir, ext));
}
