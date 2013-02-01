/*!
 * \file Log.hpp
*/

#ifndef LOG_HPP
# define LOG_HPP

#include <iostream>
#include <fstream>
#include <time.h>
#include "ILog.hpp"
#include "Config.hpp"

class Log : public ILog
{
  public:
    Log();
    virtual ~Log();

    static bool LogMessage(const std::string &message);
    static bool LogMessage(const std::string &message, const std::string &file);
};

#endif
