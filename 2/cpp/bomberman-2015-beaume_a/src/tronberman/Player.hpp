#ifndef			PLAYER_HPP_
# define		PLAYER_HPP_

# include		<string>
# include		<utility>
# include		<vector>
# include		<map>
# include		<Game.hpp>
# include		<Model.hpp>
# include		<Input.hpp>
# include		<GameClock.hpp>
# include		"myMath.hpp"
# include		"IBrain.hpp"
# include		"Map.hpp"
# include		"InterpVect.hpp"

class			MyGame;
class			Players;
class			Bombs;
class			BrainIA;
class			Map;

class			Player
{

public:

  enum			eBrain
    {
      BRAIN_IA,
      BRAIN_REAL
    };

  Player(std::string const& name);
  ~Player();

  void			draw(void);
  void			update(MyGame&);

  bool			isAlive(void) const { return _isAlive; }
  void			kill(double time);
  void			setBrain(gdl::Keys::Key tab[]);
  void			setBrain(Map* map, Bombs& bombs, Players& players);
  void			setPos(unsigned x, unsigned y);
  void			setPos(const std::pair<unsigned int, unsigned int>  &);
  void			incrPos(int x, int y, double time);

  void			incrAmmo(void) { if (_ammo < _ammoMax) ++_ammo; }
  void			decrAmmo(void) { if (_ammo) --_ammo; }

  void			incrAmmoMax(void) { _ammo = ++_ammoMax; }
  void			decrAmmoMax(void) { if (_ammoMax > 1) --_ammoMax; }
  void			incrPower(void) { if (_power < 33) ++_power; }
  void			decrPower(void) { if (_power) --_power; }
  void			faster(void) { if (_speed > .5) _speed -= .025; }
  void			slower(void) { _speed += .025; }


  unsigned		getX(void) const { return _x; }
  unsigned		getY(void) const { return _y; }
  unsigned		getPower(void) const { return _power; }
  unsigned		getAmmo(void) const { return _ammo; }

  const std::string &	getName(void) const { return this->_name; }
  bool			isHuman(void) const;

  std::string		*serialize(void);
  static Player		*unserialize(MyGame&, const std::string&);

  static unsigned	_teinte;

private:

  bool			_isAlive;
  int			_animStatus;
  IBrain*		_brain;
  std::string		_name;
  gdl::Model		_model;
  gdl::Color		_color;
  InterpVect		_pos;
  unsigned		_x, _y;
  unsigned		_power;
  Interp		_dir;
  unsigned		_ammo;
  unsigned		_ammoMax;
  double		_speed;

  typedef void (Player::*FMPTR)(void);
  std::map<int, FMPTR > _bonus;

};

#endif
