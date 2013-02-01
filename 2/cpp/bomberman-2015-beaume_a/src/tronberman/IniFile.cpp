#include "IniFile.hpp"

/*!
*   \brief  Constructor - class IniFile
*   \return None
*   \author Jonathan Salwan
*/
IniFile::IniFile() : _fileName("")
{
}


/*!
*   \brief  Constructor with file name - class IniFile
*   \param  file file name
*   \return None
*   \author Jonathan Salwan
*/
IniFile::IniFile(const std::string &file) : _fileName(file)
{
}


/*!
*   \brief  Destructor - class IniFile
*   \return None
*   \author Jonathan Salwan
*/
IniFile::~IniFile()
{
}

/*!
*   \brief  Set file for parsing - class IniFile
*   \param  file set filename
*   \return None
*   \author Jonathan Salwan
*/
void IniFile::iniFileName(const std::string &file)
{
  this->_fileName = file;
}

char *IniFile::readFile(std::ifstream &file) const
{
  char  *buffer;
  int   length;

  file.seekg(0, std::ios::end);
  length = file.tellg();
  file.seekg(0, std::ios::beg);
  buffer = new char [length];
  file.read(buffer, length);
  return (buffer);
}

std::list<std::string> IniFile::getLine(std::string buffer) const
{
  std::list<std::string> line;
  std::string tmp;
  size_t found;
  size_t last;

  last  = 0;
  found = buffer.find_first_of("\n");
  while (found != std::string::npos)
    {
      tmp.append(buffer, last, (found-last));
      line.push_back(tmp);
      last = found + 1;
      found = buffer.find_first_of("\n", found+1);
      tmp.clear();
    }
  return (line);
}

void IniFile::replaceAll(std::string& str, const std::string& from, const std::string& to)
{
  size_t start_pos = 0;
  int i = str.size();

  while (i--)
    {
      while ((start_pos = str.find(from, start_pos)) != std::string::npos)
        {
          str.replace(start_pos, from.length(), to);
          start_pos += to.length();
        }
      start_pos = 0;
    }
}

void IniFile::clearSpace(std::string &str)
{
  while (*str.data() == ' ')
    str.erase(0,1);
  while (*(str.data()+str.size()-1) == ' ')
    str.erase(str.size()-1, 1);
}

size_t IniFile::getSizeCom(const std::string& str)
{
  size_t comm;

  comm  = str.find_first_of(";");
  if (comm == std::string::npos)
    return (str.size());
  return (comm);
}

void IniFile::initLine(std::list<std::string> line)
{
  std::list<std::string>::iterator it = line.begin();
  std::string variable, content;
  size_t equal;
  size_t comm;

  while (it != line.end())
    {
      equal = (*it).find_first_of("=");
      comm  = (*it).find_first_of(";");
      if (equal != std::string::npos && comm > equal)
        {
          variable.append(*it, 0, equal);
          content.append(*it, equal+1, getSizeCom(*it) - (equal+1));
          clearSpace(variable);
          clearSpace(content);
          this->_items.push_back(std::make_pair(variable, content));
          variable.clear();
          content.clear();
        }
      it++;
    }
}

/*!
*   \brief  Set file for parsing - class IniFile
*   \return Bool
*   \author Jonathan Salwan
*
*   Return true or false if this parsing is successful.
*/
bool IniFile::parseIniFile(void)
{
  std::ifstream file(this->_fileName.c_str(), std::fstream::out | std::fstream::in);
  std::list<std::string> line;

  if (file.is_open())
    {
      std::string buffer(readFile(file));
      line = getLine(buffer);
      _items.clear();
      initLine(line);
      file.close();
    }
  else
    {
      std::cerr << "Error opening file '" << this->_fileName << "'" << std::endl;
      return (false);
    }
  return (true);
}


/*!
*   \brief  Return content variable - class IniFile
*   \param  variable get value of "variable"
*   \return std::string
*   \author Jonathan Salwan
*
*   Return the content of variable
*/
std::string IniFile::getIniFileValue(const std::string &variable)
{
  std::list< std::pair<std::string, std::string> >::iterator it;

  if (this->parseIniFile() == false)
    return ("");
  for (it = this->_items.begin(); it != this->_items.end(); it++)
    {
      if ((*it).first.compare(variable) == 0)
        return ((*it).second);
    }
  std::cerr << "Error: variable " << variable << " not found" << std::endl;
  return ("");
}

/*!
 *   \brief  Save values in ini file - class IniFile
 *   \param  const std::string &variable, const std::string &value
 *   \return bool
 *   \author Jonathan Salwan
 *
 *   Save values in ini file
 *
 *   Todo: remplacer la valeur si elle existe deja.
*/
bool IniFile::saveIniFileValue(const std::string &variable, const std::string &value)
{
  bool chk = false;
  std::list< std::pair<std::string, std::string> >::iterator it;

  if (this->parseIniFile() == false)
    return (false);
  std::ofstream file(this->_fileName.c_str(), std::ios::out);
  if (!this->_fileName.empty() && file)
    {
      for (it = this->_items.begin(); it != this->_items.end(); it++)
        {
          if ((*it).first.compare(variable) == 0)
            file << std::endl << (*it).first << " = " << value << std::endl, chk = true;
          else
            file << std::endl << (*it).first << " = " << (*it).second << std::endl;
        }
      if (!variable.empty() && !value.empty() && chk == false)
        file << std::endl << variable << " = " << value << std::endl;
      file.close();
      return (true);
    }
  else
    {
      std::cerr << "Error opening file" << std::endl;
      return (false);
    }
}

