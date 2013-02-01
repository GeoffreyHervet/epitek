#ifndef			MYMATH_HPP
# define		MYMATH_HPP

# include		<stdlib.h>
# include		<math.h>

namespace		myMath
{
  double		myFrand(double a, double b);
  double		myFmod(double a, double b);

  class			Vect
  {

  public:

    double		x, y, z;

    Vect(void);
    Vect(double x, double y, double z);
    void		init(double x, double y, double z);
    Vect const&		operator=(Vect const& v);
    Vect const&		operator*(double a);

  };

}

#endif
