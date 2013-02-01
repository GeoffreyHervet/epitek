#include		<algorithm>
#include		<sstream>
#include		<iostream>

#include		"Deleter.hpp"
#include		"Players.hpp"
#include		"PlayersNames.hpp"

Players::Players(bool &intro)
  : _intro(intro)
{}

Players::~Players()
{}

void			Players::RealsPlayers(std::string const& n1, std::string const& n2, const Map * m)
{
  Player*		p;
  gdl::Keys::Key	tab[][5] =
    {
      {gdl::Keys::W, gdl::Keys::D, gdl::Keys::S, gdl::Keys::A, gdl::Keys::E},
      {gdl::Keys::Up, gdl::Keys::Right, gdl::Keys::Down, gdl::Keys::Left, gdl::Keys::Numpad0}
    };

  p = new Player(n1);
  p->setBrain(tab[0]);
  m->setPosPlayer(p, *this);
  this->_players.push_back(p);

  if (n2 == "")
    return;
  p = new Player(n2);
  p->setBrain(tab[1]);
  m->setPosPlayer(p, *this);
  this->_players.push_back(p);
}

void			Players::putSomeBots(unsigned nb, Map* map, Bombs& bombs)
{
  Player*		p;
  unsigned		u;

  for (u = 0; u < nb; ++u)
    {
      std::stringstream	ss("");
      ss << "IA #" << u << " - " << PlayersNames[u % NB_NAMES];
      p = new Player(ss.str());
      p->setBrain(map, bombs, *this);
      map->setPosPlayer(p, *this);
      this->_players.push_back(p);
    }
}

void			Players::reset(void)
{
  std::for_each(this->_players.begin(), this->_players.end(), deleter());
  this->_players.clear();
}

void			Players::draw(void) const
{
  std::list<Player*>::const_iterator	it = this->_players.begin();

  //glDisable(GL_LIGHTING);
  for (; it != this->_players.end(); ++it)
      (*it)->draw();
  //glEnable(GL_LIGHTING);
}

void			Players::update(MyGame& game)
{
  std::list<Player*>::const_iterator    it = this->_players.begin();

  if (!this->_intro)
    for (; it != this->_players.end(); ++it)
      (*it)->update(game);
}

Player*			Players::getPlayer(unsigned x, unsigned y)
{
  std::list<Player*>::iterator	it;

  for (it = _players.begin(); it != _players.end(); ++it)
    if ((*it)->getX() == x && (*it)->getY() == y && (*it)->isAlive())
      return *it;
  return NULL;
}

Player const*		Players::getPlayer(unsigned index) const
{
  std::list<Player*>::const_iterator	it;
  unsigned		i = 0;

  if (index >= _players.size())
    return NULL;
  for (it = _players.begin(); it != _players.end(); ++it)
    {
      if (i == index)
	return *it;
      ++i;
    }
  return NULL;
}


std::vector<std::string>	Players::getHumans(void) const
{
  std::vector<std::string>	ret;

  for (std::list<Player *>::const_iterator it = this->_players.begin();
      it != this->_players.end();
      ++it)
    if ((*it)->isHuman())
      ret.push_back((*it)->getName());
  return ret;
}

int			Players::getNbIA(void) const
{
  int			ret = 0;

  for (std::list<Player *>::const_iterator it = this->_players.begin();
      it != this->_players.end();
      ++it)
    if (!(*it)->isHuman())
      ++ret;
  return ret;
}


bool			Players::haveAWinner(void) const
{
  bool			ret = false;

  if (this->_players.size() <= 1)
    return false;

  for (std::list<Player *>::const_iterator it = this->_players.begin();
      it != this->_players.end();
      ++it)
  {
    if (ret && (*it)->isAlive())
      return false;
    if ((*it)->isAlive())
    {
      this->_winner = (*it)->getName();
      ret = true;
    }
  }
  return ret;
}

