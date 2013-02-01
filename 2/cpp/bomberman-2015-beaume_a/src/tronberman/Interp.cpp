# include		<math.h>
# include		<iostream>
# include		"Interp.hpp"

Interp::Interp(double n)
  : _a(n), _n(n), _b(n),
    _timeA(0), _timeN(0), _duration(1),
    _moving(false)
{}

double		Interp::n(void) const { return _n; }
bool		Interp::isMoving(void) const { return _moving; }

void		Interp::setA(double a)
{
  _a = a;
  _n = a;
  _b = a;
}

void		Interp::incrA(double a)
{
  setA(_n + a);
}

void		Interp::setB(double b, eMouv mouv)
{
  _b = b;
  _mouv = mouv;
}

void		Interp::incrB(double b, eMouv mouv)
{
  setB(_b + b, mouv);
}

void		Interp::setDuration(double timeA, double duration)
{
  _moving = true;
  _timeA = timeA;
  _timeN = timeA;
  _duration = duration;
}

void		Interp::update(double timeN)
{
  if (!_moving)
    return;
  double n = (timeN - _timeA) / _duration;
  if (n >= 1)
    {
      _a = _n = _b;
      _moving = false;
    }
  _timeN = timeN;
  switch (_mouv)
    {
    case EASE_OUT:	n = sin(n * M_PI / 2);				break;
    case EASE_IN:	n = sin(n * M_PI / 2 - M_PI / 2) + 1;		break;
    case EASE_IN_OUT:	n = (sin(n * M_PI - M_PI / 2) + 1) / 2.;	break;
    default: break;
    }
  _n = _a + n * (_b - _a);
}
