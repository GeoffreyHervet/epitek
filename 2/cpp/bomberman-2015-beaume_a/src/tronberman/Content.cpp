# include		<sstream>
# include		<iostream>
# include		<fstream>

# include		"Content.hpp"

Content::Content() : _map(0), _nbIA(0)
{
}

Content::~Content()
{
}

void		Content::setMap(const Map &m)
{
  this->_map = new Map(m);
}

void		Content::reset(void)
{
  this->_map = 0;
  this->_nbIA = 0;
  this->_players.clear();
}

void		Content::setPlayers(const std::vector<std::string> &p)
{
  this->_players = p;
}

std::string	Content::serialize(void) const
{
  std::stringstream	ss("");

  ss
    << this->_nbIA << std::endl
    << this->_players.size() << std::endl
    << this->_map->serialize();
  std::string		ret(ss.str());
  return ret;
}

void		Content::unserialize(const std::string &fileName)
{
  std::ifstream	file(fileName.c_str());

  file >> this->_nbIA;
  int		nbPlayer;
  file >> nbPlayer;
  this->_players.clear();
  while (nbPlayer > 0)
  {
    std::stringstream	ss("Joueur ");
    ss << nbPlayer--;
    this->_players.push_back(ss.str());
  }
  if (!this->_map)
    this->_map = new Map;
  this->_map->unserialize(file);
}
