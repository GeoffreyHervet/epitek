#ifndef			INTERP_HPP
# define		INTERP_HPP

class			Interp
{

public:

  enum			eMouv
    {
      LINEAR,
      EASE_OUT,
      EASE_IN,
      EASE_IN_OUT
    };

  Interp(double n);

  void			update(double timeN);

  double		n(void) const;
  bool			isMoving(void) const;

  void			setA(double a);
  void			incrA(double a);
  void			setB(double b, eMouv mouv);
  void			incrB(double b, eMouv mouv);
  void			setDuration(double timeA, double duration);

private:

  double		_a, _n, _b;
  double		_timeA, _timeN, _duration;
  eMouv			_mouv;
  bool			_moving;

};

#endif
