#ifndef			AOBJECT_HPP
# define		AOBJECT_HPP

# include		<GameClock.hpp>
# include		<Input.hpp>
# include		<Image.hpp>
# include		"InterpVect.hpp"

class			AObject
{

public:

  AObject(void)
    : _tex(NULL),
      _pos(0, 0, 0),
      _rot(0, 0, 0),
      _sca(1, 1, 1)
  {}

  virtual void		update(gdl::GameClock const&, gdl::Input&) = 0;
  virtual void		draw(void) = 0;

  void			setTex(gdl::Image* tex) { this->_tex = tex; }
  void			setPos(int x, int y) { this->_pos.setA(x, y, 0); }

protected:

  gdl::Image*		_tex;

  InterpVect		_pos;
  InterpVect		_rot;
  InterpVect		_sca;

  int			_mapX;
  int			_mapY;

};

#endif
