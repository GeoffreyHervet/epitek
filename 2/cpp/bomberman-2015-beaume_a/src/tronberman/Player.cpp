#include		<sstream>

#include		"Error.hpp"
#include		<AnimStates.hpp>
#include		"MyGame.hpp"
#include		"BrainReal.hpp"
#include		"BrainIA.hpp"
#include		"Player.hpp"

unsigned Player::_teinte = 50;

Player::Player(std::string const& name)
  : _name(name),
    _dir(0)
{
  _isAlive = true;
  _model = gdl::Model::load("res/models/marvin.fbx");
  _model.cut_animation(this->_model, "Take 001", 0, 96, "0");
  _model.cut_animation(this->_model, "Take 001", 15, 32, "start");
  _model.cut_animation(this->_model, "Take 001", 33, 58, "run");
  _model.cut_animation(this->_model, "Take 001", 59, 96, "stop");
  setPos(1, 1);
  _power = 2;
  _ammo = _ammoMax = 5;
  _speed = .2;
  _color.r = _teinte - 50;
  _color.g = _teinte;
  _color.b = _teinte + 50;
  _teinte += 50;

  _bonus[Map::SLOWER] = &Player::slower;
  _bonus[Map::FASTER] = &Player::faster;
  _bonus[Map::DECR_BOMBS] = &Player::decrAmmoMax;
  _bonus[Map::INCR_BOMBS] = &Player::incrAmmoMax;
  _bonus[Map::DECR_POWER] = &Player::decrPower;
  _bonus[Map::INCR_POWER] = &Player::incrPower;
}

Player::~Player(void)
{
  delete this->_brain;
}

void		Player::kill(double time)
{
  _isAlive = false;
  _pos.incrB(0, 0, -2, Interp::EASE_IN);
  _pos.setDuration(time, 2);
}

void		Player::draw(void)
{
  gdl::Color	color(50, 50, 50);

  if (_isAlive)
    {
      glPushMatrix();
      glTranslatef(this->_pos.x(), this->_pos.y(), this->_pos.z());
      glScalef(.002, .002, .002);
      glRotatef(90, 1, 0, 0);
      glRotatef(this->_dir.n(), 0, 1, 0);  
      glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
      this->_model.set_default_model_color(color);
      this->_model.draw();
      //glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
      //this->_model.set_default_model_color(color_reset);
      glPopMatrix();
    }
}

void			Player::update(MyGame& game)
{
  IBrain::eAction	act = IBrain::WAIT;
  int			x, y;
  Map::eMap		e;

  if (_isAlive)
    {
      act = _brain->action(game.getInput(), &x, &y);
      if (act == IBrain::ATTACK)
	game.getBombs().putBomb(game.getMapGraph(), *this, game.totalTime(), 2);
      if (!_pos.isMoving() && (x || y))
	{
	  e = game.getMap()->getCase(_x + x, _y + y);
	  if (e != Map::UNKNOWN && e != Map::WALL && e != Map::BOX && e != Map::BOMB &&
	      !game.getPlayers().getPlayer(_x + x, _y + y))
	    {
	      if (e != Map::GROUND && _bonus[e])
		{
		  (this->*(this->_bonus[e]))();
		  
		}
	      _dir.setA(x ? 90 : 180);
	      if (x < 0 || y < 0)
		_dir.incrA(180);
	      incrPos(x, y, game.totalTime());
	      _model.play("run");
	      _model.set_anim_speed("run", 3);
	    }
	}
    }
  _pos.update(game.totalTime());
  _dir.update(game.totalTime());
  _model.update(game.getClock());
}

void		Player::setBrain(Map* map, Bombs& bombs, Players& players)
{
  this->_brain = new BrainIA(map, bombs, players, this);
}

void		Player::setBrain(gdl::Keys::Key tab[])
{
  this->_brain = new BrainReal(tab);
}

void		Player::setPos(const std::pair<unsigned int, unsigned int> &pos)
{
  this->setPos(pos.first, pos.second);
}

void		Player::setPos(unsigned x, unsigned y)
{
  this->_x = x;
  this->_y = y;
  this->_pos.setA(x + .5, y + .5, .1);
}

void            Player::incrPos(int x, int y, double time)
{
  this->_x += x;
  this->_y += y;
  this->_pos.incrB(x, y, 0, Interp::LINEAR);
  this->_pos.setDuration(time, _speed);
}

std::string	*Player::serialize(void)
{
  std::stringstream	ss("");

  ss << (reinterpret_cast<BrainReal*>(this->_brain) != 0) << ":"
    << this->_x << ":"
    << this->_y << ":"
    << this->_power << ":"
    << this->_name << std::endl;

  return new std::string(ss.str());
}

Player		*Player::unserialize(MyGame &g, const std::string &s)
{
  int		brain;
  unsigned int	x;
  unsigned int	y;
  unsigned int	power;
  std::string	name;
  char		c;

  std::stringstream ss(s);

  ss >> brain >> c;
  if (c != ':' || brain > 1 || brain < 0)
    throw Error("Player::unserialize() error - brain", Error::CRITICAL);
  ss >> x >> c;
  if (c != ':' || x > g.getMap()->getW())
    throw Error("Player::unserialize() error - x", Error::CRITICAL);
  ss >> y >> c >> power;
  if (c != ':' || y > g.getMap()->getH())
    throw Error("Player::unserialize() error - y", Error::CRITICAL);

  return 0;
}

bool			Player::isHuman(void) const
{
  return (dynamic_cast<BrainIA*>(this->_brain)) == 0;
}
