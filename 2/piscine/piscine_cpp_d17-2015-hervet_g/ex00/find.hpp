//
// find.hpp for ex00 in /home/hervet_g/piscine/piscine_cpp_d17-2015-hervet_g/ex00
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Fri Jan 20 09:27:24 2012 geoffrey hervet
// Last update Fri Jan 20 09:27:24 2012 geoffrey hervet
//

#ifndef   __FIND_HPP__
# define  __FIND_HPP__

# include	<algorithm>

template <typename T>
typename T::iterator	do_find(T &type, int find)
{
  return std::find(type.begin(), type.end(), find);
}

#endif     /* !__FIND_HPP__ */
