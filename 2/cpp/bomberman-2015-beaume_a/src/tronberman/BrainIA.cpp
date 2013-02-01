#include		<iostream>
#include		"Map.hpp"
#include		"Bombs.hpp"
#include		"BrainIA.hpp"

BrainIA::BrainIA(Map* map, Bombs& bombs, Players& players, Player* self) :
  _map(map),
  _bombs(bombs),
  _players(players),
  _self(self),
  _w(0),
  _h(0)
{
  if (_map)
    {
      _w = _map->getW();
      _h = _map->getH();
      _tmpMap.resize(_map->getW() * _map->getH(), Map::GROUND);
      _pathMap.resize(_map->getW() * _map->getH(), -1);
      _dangerMap.resize(_map->getW() * _map->getH(), -1);
      fillTmpMap();
    }
}


IBrain::eAction		BrainIA::action(gdl::Input&, int* x, int* y)
{
  eAction	act;

  *x = 0;
  *y = 0;
  fillDangerMap();
  if (amIInDanger())
    {
      Defensive();
      act = convertAction(_path.front(), x, y);
      if (!CheckNextMove(x, y) && amIInDanger())
	return IBrain::WAIT;
      if (_path.size() > 0)
	_path.pop_front();
      return act;
    }
  else
    Offensive();
  if (_path.size() > 0)
    {
      act = convertAction(_path.front(), x, y);
      if (!CheckNextMove(x, y))
	return IBrain::WAIT;
      _path.pop_front();
      return act;
    }
  return IBrain::WAIT;
}

bool		BrainIA::CheckNextMove(int *x, int *y)
{
  unsigned int	nx;
  unsigned int	ny;

  nx = *x + _self->getX();
  ny = *y + _self->getY();
  if (nx >= _w || ny >= _h || _dangerMap[ny * _w + nx] <= 0.4)
    {
      *x = 0;
      *y = 0;
      return false;
    }
  return true;
}

// ====================== MAP TEMPORAIRE ======================

void		BrainIA::fillTmpMap(void)
{
  unsigned int	i = 0;
  unsigned int	j;
  Map::eMap	ret;

  if (!_map)
    return ;
  while (i < _map->getH())
    {
      j = 0;
      while (j < _map->getW())
	{
	  ret = _map->getCase(j, i);

	  switch (ret) 
	    {
              case Map::GROUND: _tmpMap.at(i * _map->getW() + j) = Map::GROUND; break;
              case Map::BOX: _tmpMap.at(i * _map->getW() + j) = Map::BOX; break;
              case Map::WALL: _tmpMap.at(i * _map->getW() + j) = Map::WALL; break;  
              case Map::BOMB: _tmpMap.at(i * _map->getW() + j) = Map::WALL; break;  
              default: _tmpMap.at(i * _map->getW() + j) = Map::WALL;
            }
	  ++j;
	}
      ++i;
    }
}

IBrain::eAction		BrainIA::convertAction(eMovement m, int *x, int *y)
{
  *x = 0;
  *y = 0;
  switch (m)
  {
    case WAIT: return IBrain::WAIT;
    case ATTACK: return IBrain::ATTACK;
    case DOWN: *y = -1; break;
    case UP: *y = 1; break;
    case LEFT: *x = -1; break;
    case RIGHT: *x = 1; break;
    default: break;
  }
  return IBrain::MOVE;
}

void		BrainIA::displayMap(void)
{
   int i = 0;

  for (i = (_h - 1); i >= 0; --i)
    {
      for (unsigned int j = 0; j < _w; ++j)
	{
	  if (_pathMap[i * _w + j] == -2)
	    std::cout << " |";
	  else
	    std::cout << _pathMap[i * _w + j] << "|";
	}
      std::cout << std::endl;
    }
}

// =================== DANGER FINDING ===========================

void		BrainIA::PropageDangerousZone(unsigned int x,
					      unsigned int y,
					      int px,
					      int py,
					      unsigned int power,
					      double dif)
{
  x += px;
  y += py;
  while (x < _w && y < _h && power > 0 && (_map->getCase(x, y) == Map::GROUND || _map->getCase(x, y) == Map::BOMB))
    {
      if (dif < _dangerMap.at(y * _w + x))
	_dangerMap.at(y * _w + x) = dif;
      power--;
      x += px;
      y += py;
    }
}

void		BrainIA::addToDangerMap(unsigned int x, unsigned int y,
					unsigned int power)
{
  PropageDangerousZone(x, y, 1, 0, power, TIMEMAX - 1);
  PropageDangerousZone(x, y, 0, 1, power, TIMEMAX - 1);
  PropageDangerousZone(x, y, -1, 0, power, TIMEMAX - 1);
  PropageDangerousZone(x, y, 0, -1, power, TIMEMAX - 1);
}

void		BrainIA::fillDangerMap(void)
{
  std::list<Bombs::Bomb*> const		&bombsList = _bombs.getBombList();
  std::list<Bombs::Bomb*>::const_iterator	it = bombsList.begin();
  double				dif;

  _dangerMap.assign(_dangerMap.size(), TIMEMAX + 1);
  for (; it != bombsList.end() ; ++it)
    {
      dif = (*it)->timeLeft;
      if ((*it)->x < _w && (*it)->y <_h)
	_dangerMap[((*it)->y * _w) + (*it)->x];
      PropageDangerousZone((*it)->x, (*it)->y, 1, 0, (*it)->power, dif);
      PropageDangerousZone((*it)->x, (*it)->y, 0, 1, (*it)->power, dif);
      PropageDangerousZone((*it)->x, (*it)->y, -1, 0, (*it)->power, dif);
      PropageDangerousZone((*it)->x, (*it)->y, 0, -1, (*it)->power, dif);
    }
}

bool		BrainIA::amIInDanger(void)
{
  unsigned int	x = _self->getX();
  unsigned int	y = _self->getY();

  if (x >= _w || y >= _h)
    return false;
  else if (_dangerMap[y * _w + x] > TIMEMAX)
    return false;
  return true;
}

void		BrainIA::putWeigthRec(int dangerosity,
				      unsigned int x,
				      unsigned int y,
				      int weigth)
{
  if (_tmpMap.size() != (_w * _h) || x >= _w || y >= _h || weigth > 300)
    return;
  if (_tmpMap.size() == (_w * _h) &&
      _map->getCase(x, y) == Map::GROUND &&
      _map->getCase(x, y) != Map::BOMB &&
      (weigth < _pathMap[y * _w + x] || _pathMap[y * _w + x] == -2))
    {
      _pathMap[y * _w + x] = weigth;
      if (_dangerMap.size() == (_w * _h) &&
	  _dangerMap[y * _w + x] >= TIMEMAX + 1)
	{
	  _tmpCoord.x = x;
	  _tmpCoord.y = y;
	  _tmpCoord.weigth = weigth;
	  _possibilities.push_back(_tmpCoord);
	  return ;
	}
      putWeigthRec(dangerosity, x + 1, y, weigth + 1);
      putWeigthRec(dangerosity, x - 1, y, weigth + 1);
      putWeigthRec(dangerosity, x, y + 1, weigth + 1);
      putWeigthRec(dangerosity, x, y - 1, weigth + 1);
    }
}

void		BrainIA::putWeigth(int dangerosity,
				  unsigned int x,
				  unsigned int y,
				  int weigth)
{
  _possibilities.clear();
  if (x >= _w || y >= _h)
    return;
  _pathMap.assign(_pathMap.size(), -2);
  _pathMap[y * _w + x] = weigth;
  putWeigthRec(dangerosity, x + 1, y, weigth + 1);
  putWeigthRec(dangerosity, x - 1, y, weigth + 1);
  putWeigthRec(dangerosity, x, y + 1, weigth + 1);
  putWeigthRec(dangerosity, x, y - 1, weigth + 1);
}

bool		BrainIA::putWeigthCompleteRec(int dangerosity,
					      unsigned int x,
					      unsigned int y,
					      int weigth,
					      int max)
{
  bool		r;

  if (_tmpMap.size() != (_w * _h) || x >= _w || y >= _h || weigth > 100)
    return false;
  if (_tmpMap.size() == (_w * _h) && 
      _map->getCase(x, y) == Map::GROUND &&
      _map->getCase(x, y) != Map::BOMB &&
      (weigth < _pathMap[y * _w + x] || _pathMap[y * _w + x] == -2))
    {
      _pathMap[y * _w + x] = weigth;
      if (_dangerMap.size() == (_w * _h) &&
	  _dangerMap[y * _w + x] >= TIMEMAX && weigth >= max)
	{
	  _tmpCoord.x = x;
	  _tmpCoord.y = y;
	  _tmpCoord.weigth = weigth;
	  _possibilities.push_back(_tmpCoord);
	  return true;
	}
      r = !putWeigthCompleteRec(dangerosity, x + 1, y, weigth + 1, max);
      r |= !putWeigthCompleteRec(dangerosity, x - 1, y, weigth + 1, max);
      r |= !putWeigthCompleteRec(dangerosity, x, y + 1, weigth + 1, max);
      r |= !putWeigthCompleteRec(dangerosity, x, y - 1, weigth + 1, max);
      if (_dangerMap.size() == (_w * _h) && _dangerMap[y * _w + x] >= TIMEMAX)
	{
	  _tmpCoord.x = x;
	  _tmpCoord.y = y;
	  _tmpCoord.weigth = weigth;
	  _possibilities.push_back(_tmpCoord);
	}
      return true;
    }
  else
    return false;
}

void		BrainIA::putWeigthComplete(int dangerosity,
					   unsigned int x,
					   unsigned int y,
					   int weigth,
					   int max)
{
  _possibilities.clear();
  if (x >= _w || y >= _h)
    return;
  _pathMap.assign(_pathMap.size(), -2);
  _pathMap[y * _w + x] = weigth;
  putWeigthCompleteRec(dangerosity, x + 1, y, weigth + 1, max);
  putWeigthCompleteRec(dangerosity, x - 1, y, weigth + 1, max);
  putWeigthCompleteRec(dangerosity, x, y + 1, weigth + 1, max);
  putWeigthCompleteRec(dangerosity, x, y - 1, weigth + 1, max);
}

void		BrainIA::getReversePath(unsigned int x,
					unsigned int y,
					eMovement move)
{
  if (x >= _w || y >= _h)
    return ;
  if (move != UNKNOWN)
    _path.push_front(move);
  if ((x - 1 < _w && y < _h) &&
      _pathMap.at(y * _w + x) - 1 == _pathMap.at(y * _w + (x - 1)))
    getReversePath(x - 1, y, RIGHT);
  else if ((x < _w && y - 1 < _h) &&
	   _pathMap.at(y * _w + x) - 1 == _pathMap.at((y - 1) * _w + x))
    getReversePath(x, y - 1, UP);
  else if ((x < _w && y + 1 < _h) &&
	   _pathMap.at(y * _w + x) - 1 == _pathMap.at((y + 1) * _w + x))
    getReversePath(x, y + 1, DOWN);
  else if ((x + 1 < _w && y < _h) &&
	   _pathMap.at(y * _w + x) - 1 == _pathMap.at(y * _w + (x + 1)))
    getReversePath(x + 1, y, LEFT);
}

void		BrainIA::buildBestPath(void)
{
  std::list<t_coord>::iterator	it;
  std::list<t_coord>::iterator	best;
  bool				f = true;

  _path.clear();
  for (it = _possibilities.begin() ; it != _possibilities.end() ; ++it)
    {
      if (f)
	{
	  f = false;
	  best = it;
	}
      else if ((*it).weigth < (*best).weigth)
	best = it;
    }
  if (!f)
    getReversePath((*best).x, (*best).y, UNKNOWN);
}

void		BrainIA::Defensive(void)
{
  putWeigth(0, _self->getX(), _self->getY(), 0);
  buildBestPath();
}

// OFFENSIVE PART ======================

inline bool		BrainIA::thereIsanEscape()
{
  return (_possibilities.size() != 0);
}

bool		BrainIA::tryToPutBomb(void)
{
  _dangerMap.assign(_dangerMap.size(), -2);
  fillDangerMap();
  addToDangerMap(_self->getX(), _self->getY(), _self->getPower());
  putWeigth(0, _self->getX(), _self->getY(), 0);
  if (thereIsanEscape() && _self->getX() < _w && _self->getY() < _h &&
      _map->getCase(_self->getX(), _self->getY()) != Map::BOMB)
    {
      _path.push_front(ATTACK);
      return true;
    }
  return false;
}

bool		BrainIA::checkPath(void)
{
  std::list<enum eMovement>::const_iterator	it;
  unsigned int					x;
  unsigned int					y;
  int						mx;
  int						my;
  
  x = _self->getX();
  y = _self->getY();
  for (it = _path.begin() ; it != _path.end() ; ++it)
    {
      mx = 0;
      my = 0;
      if (!(x < _w && y < _h))
	return false;
      if (_map->getCase(x, y) != Map::GROUND && 
	  _dangerMap[y * _w + x] >= TIMEMAX)
	return false;
      convertAction((*it), &mx, &my);      
      x += mx;
      y += my;
    }
  return true;
}

bool		BrainIA::isReachDirection(unsigned int x, unsigned int y,
					  int px, int py, unsigned int power,
					  Map::eMap type)
{
  unsigned int	i = 0;

  x += px;
  y += py;
  while (i < power)
    {
      if (x < _w && y < _h)
	{
	  if (_map->getCase(x, y) == type)
	    return true;
	  else if (_map->getCase(x, y) != Map::GROUND)
	    return false;
	}
      x += px;
      y += py;
      ++i;
    }
  return false;
}

bool		BrainIA::isReach(unsigned int x, unsigned int y,
				 unsigned int power, Map::eMap type)
{
  return (isReachDirection(x, y, 1, 0, power, type) ||
	  isReachDirection(x, y, -1, 0, power, type) ||
	  isReachDirection(x, y, 0, 1, power, type) ||
	  isReachDirection(x, y, 0, -1, power, type));
}

bool		BrainIA::isReachPlayerDirection(unsigned int x, unsigned int y,
						int px, int py, unsigned int power)
{
  unsigned int	i = 0;
  Player	*player;

  x += px;
  y += py;
  while (i < power)
    {
      if (x < _w && y < _h)
	{
	  if ((player = _players.getPlayer(x, y)) != NULL &&
	      player != _self)
	    return true;
	  else if (_map->getCase(x, y) != Map::GROUND)
	    return false;
	}
      x += px;
      y += py;
      ++i;
    }
  return false;
}

bool		BrainIA::isReachPlayer(unsigned int x, unsigned int y,
				       unsigned int power)
{
  return (isReachPlayerDirection(x, y, 1, 0, power) ||
	  isReachPlayerDirection(x, y, -1, 0, power) ||
	  isReachPlayerDirection(x, y, 0, 1, power) ||
	  isReachPlayerDirection(x, y, 0, -1, power));
}

void		BrainIA::SelectObjective(void)
{
  unsigned int	size;
  std::list<t_coord>::iterator	it;
  std::list<t_coord>::iterator	best;
  bool				b = true;

  best = _possibilities.end();
  for (it = _possibilities.begin() ; (b && it != _possibilities.end()) ; ++it)
    {
      if (isReachPlayer((*it).x, (*it).y, _self->getPower()))
      {
	b = false;
	best = it;
      }
      if (b && isReach((*it).x, (*it).y, _self->getPower(), Map::BOX))
	best = it;
    }
  if ((size = _possibilities.size()) != 0)
    {
      if (best == _possibilities.end())
	{
	  best = _possibilities.begin();
	  std::advance(best, random() % size);
	}
      _path.clear();
      getReversePath((*best).x, (*best).y, UNKNOWN);
    }
}

void		BrainIA::Offensive(void)
{
  if ((isReach(_self->getX(), _self->getY(), _self->getPower(), Map::BOX)
       || isReachPlayer(_self->getX(), _self->getY(), _self->getPower()))
      && (random() % 1 == 0) && tryToPutBomb())
    return;
  if (_path.size() > 0 && checkPath())
      return;
  _path.clear();
  fillDangerMap();
  putWeigthComplete(0, _self->getX(), _self->getY(), 0, (random() % 100) + 1);
  SelectObjective();
}
