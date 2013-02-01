#include <vector>
#include <sstream>
#include <fcntl.h>
#include <fstream>
#include <iostream>

#include "Core.h"
#include "Opts.h"
#include "DLLoader.h"
#include "IGraphic.h"

static	int		getValue(char *str)
{
  int			value;
  std::stringstream	is(str);

  is >> value;
  return (value);
}

static	int		checkValue(int value)
{
  if (value < MIN_SIZE_MAP || value > MAX_SIZE_MAP)
    {
      std::cerr << ERR_MAP_SIZE << std::endl;
      return (0);
    }
  return 1;
}

static std::vector<std::vector<bool> >loadMap(const std::string &fileName)
{
  std::ifstream file;
  char          buf[1024];
  std::vector<std::vector<bool> >ret;

  buf[0] = 0;
  file.open(fileName.c_str(), std::ifstream::out);
  if (false == file.is_open())
  {
    std::cerr << fileName << ": No such file" << std::endl;
    return ret;
  }
  while (!file.eof())
  {
    std::vector<bool>	tmp;
    file.getline(buf, 1023);
    for (size_t idx = 0; buf[idx]; ++idx)
      tmp.push_back(buf[idx] != '.' && buf[idx] != ' ');
    if (!tmp.empty())
    {
      if (!ret.empty() && ret[0].size() != tmp.size())
      {
        std::cerr << "Error ! Your map was't valid ! Check lines size ..." << std::endl;
        return std::vector<std::vector<bool> >();
      }
      else
        ret.push_back(tmp);
    }
  }
  file.close();
  if (ret.empty())
  {
    std::cerr << "Error ! Your map was empty O_o" << std::endl;
    return std::vector<std::vector<bool> >();
  }
  return ret;
}

int	main(int ac, char **av)
{
  int	width;
  int	height;
  Opts	infos(ac, av, "?");
  std::vector<std::vector<bool> > map;

  if ((ac != 3) && ac != 4 && (ac != 3 && !infos.haveOption("map")))
  {
    std::cerr << "Usage: ./nibbler width height libname.so" << std::endl;
    std::cerr << "  Or : ./nibbler --map=map.file libname.so" << std::endl;
    return (1);
  }

  if (infos.haveOption("map"))
  {
    map = loadMap(infos["map"]);
    if (map.empty())
      return 1;
    height = map.size();
    width = 0;
    if (height)
      width = map[0].size();
    if (map.empty())
      return (1);
  }

  else
  {
    width = getValue(av[1]);
    height = getValue(av[2]);
  }

  try
  {
    if (checkValue(width) && checkValue(height))
      {
	Nibbler::IGraphic	*tmp = (reinterpret_cast<Nibbler::IGraphic *(*)(int, int, int, char **)> (DLLoader::getInstance(av[ac - 1])))(width, height, ac, av);
	Nibbler::Core	kore(map, width, height, tmp);
	kore.run();
	DLLoader::closeHandlers();
      }
  }
  catch (const std::exception &e)
  {
    std::cerr << "[ERROR] " << e.what() <<std::endl;
    return 1;
  }

  return 0;
}
