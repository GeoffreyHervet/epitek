#include		"myMath.hpp"

namespace		myMath
{

  double		myFrand(double a, double b)
  {
    return a + rand() / (double)(RAND_MAX) * (b - a);
  }
  
  double		myFmod(double a, double b)
  {
    return a > 0 ? fmod(a, b) : b - fmod(-a, b);
  }

  /* Vecteur */
  
  Vect::Vect(void)
    : x(0), y(0), z(0)
  {}

  Vect::Vect(double x, double y, double z)
    : x(x), y(y), z(z)
  {}

  void                  Vect::init(double x, double y, double z)
  {
    this->x = x;
    this->y = y;
    this->z = z;
  }

  Vect const&		Vect::operator=(Vect const& v)
  {
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
    return *this;
  }

  Vect const&		Vect::operator*(double a)
  {
    this->x *= a;
    this->y *= a;
    this->z *= a;
    return *this;
  }

}
