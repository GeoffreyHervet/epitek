#ifndef			INTERPVECT_HPP
# define		INTERPVECT_HPP

# include		"Interp.hpp"

class			InterpVect
{

public:

  InterpVect(void) : _x(0), _y(0), _z(0) {}
  InterpVect(double x, double y, double z) : _x(x), _y(y), _z(z) {}

  double		x(void) const { return this->_x.n(); }
  double		y(void) const { return this->_y.n(); }
  double		z(void) const { return this->_z.n(); }

  bool			isMoving(void);
  void			setA(double x, double y, double z);
  void			incrA(double x, double y, double z);
  void			setB(double x, double y, double z, Interp::eMouv mouv);
  void			incrB(double x, double y, double z, Interp::eMouv mouv);
  void			setDuration(double timeA, double duration);
  void			update(double timeN);

private:

  Interp		_x, _y, _z;

};

#endif
