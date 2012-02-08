#include <string>
#include <map>
#include <list>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include "Trace.h"

#include "CPU.h"

bool isNumeric(std::string str)
{
  for (int i = 0; i == 0 || str.length(); ++i)
    {
      if (str[i] < 48 || str[i] > 57)
	return false;
    }
  return true;
}

Mod::CPU::CPU()
  :_model(""), _coreNbr(0), _frequency(0.0), _temperature("Undefined")
{
  PRINT_TRACE();
  this->updateInfo();
  gettimeofday(&this->_timestamp, NULL);
}

Mod::CPU::~CPU()
{
  PRINT_TRACE();
#ifdef TRACE
  std::clog << "CPU: "
	    << "Model : " << this->_model << ", "
	    << "Nb Core : " << this->_coreNbr << ", "
	    << "Frequence: " << this->_frequency << "MHz, "
	    << "Temperature: " << this->_temperature << std::endl;
  std::clog << "Dump CPU Activity: " << std::endl;
  for(std::map<std::string, float>::iterator it = this->_activity.begin(); it != this->_activity.end(); ++it ) {
    std::clog << "name: " << it->first
	      << ", usage: " << it->second << "%" << std::endl;
  }
#endif
}

void Mod::CPU::updateInfo()
{
  PRINT_TRACE();
  std::ifstream in("/proc/cpuinfo");
  std::string str;
  std::map<std::string, void (Mod::CPU::*)(std::string)> words;

  words["model name"] = &Mod::CPU::setModel;
  words["cpu cores"] = &Mod::CPU::setCoreNbr;
  words["cpu MHz"] = &Mod::CPU::setFrequency;
  words["temperature"] = &Mod::CPU::setTemperature;

  if (!in.good())
    return;

  while (!in.eof())
    {
      getline(in, str);
      for(std::map<std::string, void (Mod::CPU::*)(std::string)>::iterator it = words.begin(); it != words.end(); ++it )
	{
	  if (str.find(it->first) != std::string::npos)
	    (this->*(it->second))(str);
	}
    }
  this->setActivity();
}

void Mod::CPU::setModel(std::string str)
{
  PRINT_TRACE();
  str = str.substr(str.find(": ") + 2);
  this->_model = str;
}

void Mod::CPU::setCoreNbr(std::string str)
{
  PRINT_TRACE();
  str = str.substr(str.find(": ") + 2);
  this->_coreNbr = atoi(str.c_str());
}

void Mod::CPU::setFrequency(std::string str)
{
  PRINT_TRACE();
  str = str.substr(str.find(": ") + 2);
  this->_frequency = atof(str.c_str());
}

void Mod::CPU::setTemperature(std::string str)
{
  PRINT_TRACE();
  str = str.substr(str.find(": ") + 2);
  this->_temperature = str;
}

void Mod::CPU::setActivity()
{
  PRINT_TRACE();
  static bool initialised = false;
  std::ifstream in("/proc/stat");
  std::string str;
  activityStats act;
  std::list<activityStats>::iterator it;
  timeval t;
  float result;

  gettimeofday(&t, NULL);
  /* Lecture de la date et de l'heure */

  act.work = 0;
  act.total = 0;
  if (!in.good())
    return;

  in >> str;
  while (!in.eof())
    {
      if (str.find("cpu") != std::string::npos)
	{
	  act.name = str;
	  in >> str;
	  for (int i = 0; i < 10; i++)
	    {
	      if (i < 3)
		act.work += atoi(str.c_str());
	      act.total += atoi(str.c_str());
	      in >> str;
	    }
	  if (initialised == false)
	    this->_activityStats.push_back(act);

	  for( it = this->_activityStats.begin(); it != this->_activityStats.end(); ++it )
	    {
	      if (it->name == act.name)
		break;
	    }

	  result = ((float)it->work - (float)act.work) / ((float)it->total - (float)act.total) * 100;
	  if (result <= 0) result = 0.000001;
	  this->_activity[act.name] = (result);
	  this->_activityStats.erase(it);
	  this->_activityStats.push_back(act);
	  act.work = 0;
	  act.total = 0;
	}
      else
	in >> str;
      }
  initialised = true;
  this->_timestamp = t;
}

std::string const& Mod::CPU::getModel() const
{
  return this->_model;
}

std::map<std::string, float> const& Mod::CPU::getActivity() const
{
  return this->_activity;
}

unsigned int Mod::CPU::getCoreNbr() const
{
  return this->_coreNbr;
}

float Mod::CPU::getFrequency() const
{
  return this->_frequency;
}

std::string const& Mod::CPU::getTemperature() const
{
  return this->_temperature;
}
