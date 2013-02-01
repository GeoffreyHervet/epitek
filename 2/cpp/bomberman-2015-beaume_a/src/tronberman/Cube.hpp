#ifndef			CUBE_HPP
# define		CUBE_HPP

# include		<iostream>
# include		<Image.hpp>
# include		"AObject.hpp"

class			Cube : public AObject
{
  
public:

  Cube(void)
  {
    this->_rot.setA(0, 0, 180);
    this->_sca.setA(.1, .1, .1);
  }
  
  virtual void		update(gdl::GameClock const&, gdl::Input&);
  virtual void		draw(void);
  double		getScaleZ(void) const { return this->_sca.z(); }

  void			setRotZ(double z, double time)
  {
    this->_rot.setB(0, 0, z, Interp::EASE_IN);
    this->_rot.setDuration(time, 1);
  }

  void			setScale(double z, double time, double duration)
  {
    this->_sca.setB(1, 1, z, Interp::EASE_IN);
    this->_sca.setDuration(time, duration);
  }

};

#endif
