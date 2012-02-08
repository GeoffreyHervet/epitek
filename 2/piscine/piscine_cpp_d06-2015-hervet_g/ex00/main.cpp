//
// main.cpp for ex00 in /home/hervet_g/piscine/cpp/ex00
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Mon Jan 09 11:16:34 2012 geoffrey hervet
// Last update Mon Jan 09 11:16:34 2012 geoffrey hervet
//

#include	<string>
#include	<iostream>
#include	<fstream>
#include	<iomanip>

void		cat(char const *fileName)
{
  std::ifstream	file;
  char		buf[255];

  buf[0] = 0;
  file.open(fileName, std::ifstream::out);
  if (false == file.is_open())
    std::cerr << "my_cat: " << fileName << ": No such file or directory" << std::endl;
  else
  {
    while (!file.eof())
    {
      file.read(buf, 254);
      buf[file.gcount()] = 0;
      std::cout << buf;
    }
    file.close();
  }
}

int		main(int ac, char **av)
{
  int		idx = 1;

  if (ac == 1)
    std::cerr << "my_cat: Usage : " << av[0] << " file [...]" << std::endl;
  while (idx < ac)
    cat(av[idx++]);
  return 0;
}
