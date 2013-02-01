#ifndef INIFILE
# define INIFILE

# include <iostream>
# include <fstream>
# include <list>

/*!
*   \class  IniFile IniFile.hpp
*   \brief  .ini file handling
*   \author Jonathan Salwan
*
*   .ini file handling
*/
class IniFile
{
  private:
    std::string _fileName;
    std::list< std::pair<std::string, std::string> > _items;

    char *readFile(std::ifstream &file) const;
    std::list<std::string> getLine(std::string buffer) const;
    void initLine(std::list<std::string> line);
    void replaceAll(std::string& str, const std::string& from, const std::string& to);
    void clearSpace(std::string& str);
    size_t getSizeCom(const std::string& str);

  public:
    IniFile();
    IniFile(const std::string &fileName);
    virtual ~IniFile();

    void iniFileName(const std::string &fileName);
    bool parseIniFile(void);
    std::string getIniFileValue(const std::string &variable);
    bool saveIniFileValue(const std::string &variable, const std::string &value);
};

#endif
