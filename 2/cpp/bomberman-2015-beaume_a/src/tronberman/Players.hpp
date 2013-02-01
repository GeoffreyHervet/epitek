#ifndef			PLAYERS_HPP
# define		PLAYERS_HPP

# include		<list>
# include		<string>

# include		"Player.hpp"

class			Players
{

public: 

  Players(bool &);
  virtual ~Players(void);

  void			RealsPlayers(std::string const& n1, std::string const& n2, const Map* map);
  void			putSomeBots(unsigned nb, Map* map, Bombs& bombs);

  void			draw(void) const;
  void			update(MyGame& game);
  void			reset(void);

  inline unsigned int	getNbPlayers(void) const { return this->_players.size(); }
  Player*		getPlayer(unsigned x, unsigned y);
  Player const*		getPlayer(unsigned index) const;

  std::vector<std::string> getHumans(void) const;
  int			 getNbIA(void) const;
  bool			haveAWinner(void) const;
  const std::string	&getWinner(void) const { return this->_winner; };

private:

  bool			&_intro;
  std::list<Player*>	_players;
  mutable std::string		_winner;
};

#endif
