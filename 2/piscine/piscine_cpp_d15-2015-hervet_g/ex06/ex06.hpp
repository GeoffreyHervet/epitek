//
// ex06.hpp for ex06 in /home/hervet_g/piscine/piscine_cpp_d15-2015-hervet_g/ex06
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Wed Jan 18 14:36:45 2012 geoffrey hervet
// Last update Wed Jan 18 14:36:45 2012 geoffrey hervet
//

#include	<string>
#include	<sstream>
#include	<iostream>

#ifndef   __EX06_HPP__
# define  __EX06_HPP__

template <typename X>
static std::string getType(const X &a){ return "[???]"; };

static std::string getType(const int &a)
{
  std::ostringstream ret;
  ret << "[int:" << a << "]";
  return ret.str();
};

static std::string getType(const float &a)
{
  std::ostringstream ret;
  ret << "[float:" << a << "f]";
  return ret.str();
};

static std::string getType(const std::string &a)
{
  std::ostringstream ret;
  ret << "[string:\"" << a << "\"]";
  return ret.str();
};

template <typename X, typename Y = X>
struct		Tuple
{
  X		a;
  Y		b;

  std::string	toString(void) const
  {
    std::ostringstream	ret;
    std::string		type;

    ret <<  "[TUPLE " << getType(this->a) << " " <<  getType(this->b) << "]";
    return ret.str();
  };
};

#endif     /* !__EX06_HPP__ */
