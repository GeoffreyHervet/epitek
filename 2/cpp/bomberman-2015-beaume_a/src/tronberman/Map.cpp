#include	<stdlib.h>
#include	<utility>
#include	<string>
#include	<fstream>
#include	<sstream>
#include	<iostream>

#include	"Map.hpp"
#include	"Player.hpp"

Map::Map(void)
{
  _w = 0;
  _h = 0;
}

Map::Map(unsigned w, unsigned h)
{
  init(w, h);
}

void		Map::init(unsigned w, unsigned h)
{
  _w = w;
  _h = h;
  _map.clear();
  _map.resize(w * h, Map::GROUND);
}

void		Map::randomize(void)
{
  for (unsigned int x = 0; x < _w; ++x)
    for (unsigned int y = 0; y < _h; ++y)
      if (!(rand() % 10))
        _map[x * _w + y] = Map::WALL;
      else if (!(rand() % 5))
        _map[x * _w + y] = Map::BOX;
}

void		Map::wallAround(void)
{
  unsigned	u;

  for (u = 0; u < _w; ++u)
    {
      _map[u] = Map::WALL;
      _map[(_h - 1) * _w + u] = Map::WALL;
    }
  for (u = 0; u < _h; ++u)
    {
      _map[u * _w] = Map::WALL;
      _map[(u + 1) * _w - 1] = Map::WALL;
    }
}

bool			Map::loadFile(std::string const& path)
{
  std::ifstream		file(path.c_str());

  return this->unserialize(file);
}

bool			Map::unserialize(std::ifstream& file)
{
  std::string		str;
  unsigned		u = 0, v, height;

  file >> _w;
  file >> _h;
  if (!_w || !_h)
    return false;
  this->_map.resize(_w * _h, Map::GROUND);
  this->wallAround();
  for (height = 0; height < _h && (file >> str); ++height)
    {
      for (v = 0; v < str.size() && v < _w; ++v, ++u)
	if ((_map[u] = static_cast<eMap>(str[v] - '0')) >= Map::UNKNOWN)
        {
	  _map[u] = Map::GROUND;
        }
        else if ((int(_map[u]) < 0) || int(_map[u]) >= int(Map::UNKNOWN))
          return false;
    }
  return true;
}

std::string		Map::serialize(void) const
{
  std::stringstream	ss("");
  
  ss << this->_w << std::endl;
  ss << this->_h << std::endl;
  for (unsigned u = 0; u < this->_map.size(); ++u)
    {
      ss << this->_map[u];
      if (!((u + 1) % this->_w))
	ss << std::endl;
    }

  std::string		ret(ss.str());
  return ret;
}

void			Map::setPosPlayerDefault(Player *p, Players &players) const
{
  unsigned int		i = 0;
  bool			b = true;

  while (i < _w * _h && _w != 0 && _h != 0)
    {
      if (this->getCase(i % _w, i / _w) == Map::GROUND &&
	  players.getPlayer(i % _w, i / _w) == NULL)
	{
	  b = false;
	  break;
	}
      i++;
    }
  if (!b)
    p->setPos(i % _w, i / _w);
  else
    p->setPos(0, 0);
}

void			Map::setPosPlayer(Player *p, Players &players) const
{
  std::pair<unsigned int, unsigned int>	pos(0, 0);

  int			i = 0;
  bool			b = false;

  while (++i < 100)
  {
    pos.first = rand() % this->_w;
    pos.second = rand() % this->_h;
    if (this->getCase(pos.first, pos.second) == Map::GROUND &&
	players.getPlayer(pos.first, pos.second) == NULL)
      {
	b = true;
	break;
      }
  }
  if (!b)
    setPosPlayerDefault(p, players);
  else
    p->setPos(pos);
}
