#ifndef			LIGHTS_HPP
# define		LIGHTS_HPP

# include		<math.h>
# include		<GL/gl.h>
# include		<GL/glu.h>
# include		<GameClock.hpp>
# include		<Input.hpp>

# define		NB_LIGHTS	6

class			Lights
{

public:

  void			initialize(void);

  void			update(gdl::GameClock const &, gdl::Input &);

  GLfloat		getPosX(unsigned l) const { return this->_pos[l][0]; }
  GLfloat		getPosY(unsigned l) const { return this->_pos[l][1]; }
  GLfloat		getPosZ(unsigned l) const { return this->_pos[l][2]; }

  GLfloat const*	getAmb(unsigned l) const { return this->_amb[l]; };
  GLfloat const*	getDif(unsigned l) const { return this->_dif[l]; };

  void			setPosX(unsigned l, GLfloat x) { this->_pos[l][0] = x; this->updatePos(l); }
  void			setPosY(unsigned l, GLfloat y) { this->_pos[l][1] = y; this->updatePos(l); }
  void			setPosZ(unsigned l, GLfloat z) { this->_pos[l][2] = z; this->updatePos(l); }
  void			setPos(unsigned l, GLfloat x, GLfloat y, GLfloat z)
  {
    this->_pos[l][0] = x;
    this->_pos[l][1] = y;
    this->_pos[l][2] = z;
    this->updatePos(l);
  }

  void			setAmbR(unsigned l, GLfloat r) { this->_amb[l][0] = r; this->updateAmb(l); }
  void			setAmbG(unsigned l, GLfloat g) { this->_amb[l][1] = g; this->updateAmb(l); }
  void			setAmbB(unsigned l, GLfloat b) { this->_amb[l][2] = b; this->updateAmb(l); }
  void			setAmb(unsigned l, GLfloat r, GLfloat g, GLfloat b)
  {
    this->_amb[l][0] = r;
    this->_amb[l][1] = g;
    this->_amb[l][2] = b;
    this->updateAmb(l);
  }

  void			setDifR(unsigned l, GLfloat r) { this->_dif[l][0] = r; this->updateDif(l); }
  void			setDifG(unsigned l, GLfloat g) { this->_dif[l][1] = g; this->updateDif(l); }
  void			setDifB(unsigned l, GLfloat b) { this->_dif[l][2] = b; this->updateDif(l); }
  void			setDif(unsigned l, GLfloat r, GLfloat g, GLfloat b)
  {
    this->_dif[l][0] = r;
    this->_dif[l][1] = g;
    this->_dif[l][2] = b;
    this->updateDif(l);
  }

private:

  void			updatePos(unsigned l) { glLightfv(GL_LIGHT0 + l, GL_POSITION, this->_pos[l]); }
  void			updateAmb(unsigned l) { glLightfv(GL_LIGHT0 + l, GL_AMBIENT, this->_amb[l]); }
  void			updateDif(unsigned l) { glLightfv(GL_LIGHT0 + l, GL_DIFFUSE, this->_dif[l]); }

  GLfloat		_pos[NB_LIGHTS][4];
  GLfloat		_amb[NB_LIGHTS][4];
  GLfloat		_dif[NB_LIGHTS][4];
};

#endif
