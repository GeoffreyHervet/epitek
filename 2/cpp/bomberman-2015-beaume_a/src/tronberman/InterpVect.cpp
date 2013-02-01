# include	"InterpVect.hpp"

bool			InterpVect::isMoving(void)
{
  return this->_x.isMoving() || this->_y.isMoving() || this->_z.isMoving();
}

void			InterpVect::setA(double x, double y, double z)
{
  this->_x.setA(x);
  this->_y.setA(y);
  this->_z.setA(z);
}

void			InterpVect::incrA(double x, double y, double z)
{
  this->_x.incrA(x);
  this->_y.incrA(y);
  this->_z.incrA(z);
}

void			InterpVect::setB(double x, double y, double z, Interp::eMouv mouv)
{
  this->_x.setB(x, mouv);
  this->_y.setB(y, mouv);
  this->_z.setB(z, mouv);
}

void			InterpVect::incrB(double x, double y, double z, Interp::eMouv mouv)
{
  this->_x.incrB(x, mouv);
  this->_y.incrB(y, mouv);
  this->_z.incrB(z, mouv);
}

void			InterpVect::setDuration(double timeA, double duration)
{
  this->_x.setDuration(timeA, duration);
  this->_y.setDuration(timeA, duration);
  this->_z.setDuration(timeA, duration);
}

void			InterpVect::update(double timeN)
{
  this->_x.update(timeN);
  this->_y.update(timeN);
  this->_z.update(timeN);
}
