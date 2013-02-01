#ifndef			MAP_HPP
# define		MAP_HPP

# include		<string>
# include		<vector>
# include		"Players.hpp"

class			Player;
class			Players;

class			Map
{

public:

  enum			eCount
    {
      NB_BOMBS = 6,
      NB_BONUS = 6
    };

  enum			eMap
    {
      GROUND,
      BOX,
      WALL,
      BOMB, BOMB2, BOMB3, BOMB4, BOMB5, LAST_BOMB,
      SLOWER, DECR_BOMBS, INCR_BOMBS, DECR_POWER, INCR_POWER, FASTER,
      UNKNOWN
    };

  Map(void);
  Map(unsigned w, unsigned h);

  void			init(unsigned w, unsigned h);
  void			wallAround(void);
  void			randomize(void);
  bool			loadFile(std::string const& path);

  unsigned		getW(void) const { return _w; }
  unsigned		getH(void) const { return _h; }
  eMap			getCase(unsigned x, unsigned y) const { return x < _w && y < _h ? _map[y * _w + x] : UNKNOWN; }
  eMap			getCase(unsigned ind) const { return ind < _w * _h ? _map[ind] : UNKNOWN; }
  void			setCase(unsigned x, unsigned y, eMap e) { if (x < _w && y < _h) _map[y * _w + x] = e; }
  void			setCase(unsigned ind, eMap e) { if (ind < _w * _h) _map[ind] = e; }

  void			setPosPlayer(Player *p, Players &players) const;
  void			setPosPlayerDefault(Player *p, Players &players) const;
  std::string		serialize(void) const;
  bool			unserialize(std::ifstream &);

private:

  unsigned		_w;
  unsigned		_h;
  std::vector<eMap>	_map;
  eMap*			_buf;
};

#endif
