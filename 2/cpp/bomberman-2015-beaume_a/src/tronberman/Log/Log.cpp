/*!
 * \file Log.cpp
*/

#include "Log.hpp"

Log::Log()
{
}

Log::~Log()
{
}

/*!
 *   \brief  Log message in file log - static methode
 *   \param  message Log this message
 *   \return bool
 *   \author Jonathan Salwan
 *
 *   Log message in default log file and return true or false
*/
bool Log::LogMessage(const std::string &message)
{
  std::ofstream outFile;
  time_t        rawtime;

  if (Config::DefaultLogFile.empty())
    {
      std::cerr << "Error: Config::DefaultLogFile is empty" << std::endl;
      return false;
    }
  outFile.open(Config::DefaultLogFile.c_str(), std::ios_base::app);
  if (!outFile.is_open())
    {
      std::cerr << "Error: Opening file " << Config::DefaultLogFile << std::endl;
      return false;
    }
  time(&rawtime);
  std::string timeLog(ctime(&rawtime));
  timeLog.replace(timeLog.size()-1, 1, "");
  outFile << "[" << timeLog << "] " << message << std::endl;
  outFile.close();
  return true;
}

/*!
 *   \brief  Log message in file log with specific log file - static methode
 *   \param  message Log this message
 *   \param  file Define a specific log file
 *   \return bool
 *   \author Jonathan Salwan
 *
 *   Log message in default log file and return true or false
*/
bool Log::LogMessage(const std::string &message, const std::string &file)
{
  std::ofstream outFile;
  time_t        rawtime;

  if (file.empty())
    {
      std::cerr << "Error: file log is empty" << std::endl;
      return false;
    }
  outFile.open(file.c_str(), std::ios_base::app);
  if (!outFile.is_open())
    {
      std::cerr << "Error: Opening file " << file << std::endl;
      return false;
    }
  time(&rawtime);
  std::string timeLog(ctime(&rawtime));
  timeLog.replace(timeLog.size()-1, 1, "");
  outFile << "[" << timeLog << "] " << message << std::endl;
  outFile.close();
  return true;
}
