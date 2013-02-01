#ifndef CONTENT_HPP_
# define CONTENT_HPP_

# include	<string>
# include	<vector>

# include	"Map.hpp"

class		Content
{
  private:
    Content(const Content &);
    Content &operator=(const Content &);

  public:
    Content();
    ~Content();
    
    const Map			*getMap() const { return this->_map; };
    void			 setMap(const Map &);

    int				 getNbIA() const { return this->_nbIA; };
    void			 setNbIA(int n) { this->_nbIA = n; };
    
    void			 reset(void);

    void			 setPlayers(const std::vector<std::string> &);
    const std::vector<std::string>&getPlayers(void) const { return this->_players; };

    std::string			serialize(void) const;
    void			unserialize(const std::string &);

  private:
    Map				*_map;
    int				 _nbIA;
    std::vector<std::string>	 _players;
};

#endif /* CONTENT_HPP_ */
