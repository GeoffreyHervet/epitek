#include		<math.h>
#include		"SDLazy_Circle.h"

void			SDLazy_SetPix_Secure(SDL_Surface *srf, int x, int y, Uint32 px);

static double		_get_angle(int x, int y, double r)
{
  if (x > r / -2.0 && x < r / 2.0)
    {
      if (y < 0)
        return 2 * M_PI - acos(x / r);
      return acos(x / r);
    }
  if (x < 0)
    return M_PI - asin(y / r);
  if (y < 0)
    return 2 * M_PI + asin(y / r);
  return asin(y / r);
}

static void		_circle_1px(SDLazy_Circle* c, int x, int y, Uint32 col)
{
  double		a = _get_angle(x, y, c->r_tmp);

  if (c->full_circle ||
      (c->deg[0] < a && a < c->deg[1]) ||
      (c->deg[0] > c->deg[1] && (c->deg[0] < a || a < c->deg[1])))
    SDLazy_SetPix_Secure(c->srf, c->x + x, c->y + y, col);
}

static void		_circle_8px(SDLazy_Circle* c, int x, int y, Uint32 col)
{
  _circle_1px(c,  x,  y, col);
  _circle_1px(c,  y,  x, col);
  _circle_1px(c, -x,  y, col);
  _circle_1px(c, -y,  x, col);
  _circle_1px(c,  x, -y, col);
  _circle_1px(c,  y, -x, col);
  _circle_1px(c, -x, -y, col);
  _circle_1px(c, -y, -x, col);
}

static void		_andres(SDLazy_Circle* c, double col[])
{
  int			x = 0;
  int			y = c->r_tmp;
  int			a = y - 1;
  Uint32		_col = SDL_MapRGB(c->srf->format, col[0], col[1], col[2]);

  while (y >= x)
    {
      _circle_8px(c, x, y, _col);
      if (a >= 2 * x)
        {
          a -= 2 * x;
          ++x;
        }
      else if (a <= 2 * (c->r_tmp - y))
        {
          a += 2 * y;
          --y;
        }
      else
        {
          a += 2 * (y - x);
          --y;
          ++x;
        }
    }
}

void			SDLazy_DrawCircle(SDLazy_Circle* c)
{
  double		r_int;
  double		col_inc[3];
  double		col_tmp[3];

  if (c->border_size > 0)
    {
      r_int = c->r;
      c->r_tmp = c->r + c->border_size;
    }
  else
    {
      c->r_tmp = c->r;
      r_int = c->r + c->border_size;
    }

  c->deg[0] = fmod(c->deg[0], 2 * M_PI);
  c->deg[1] = fmod(c->deg[1], 2 * M_PI);

  col_inc[0] = (c->col_ext.r - c->col_int.r) / (r_int - c->r_tmp);
  col_inc[1] = (c->col_ext.g - c->col_int.g) / (r_int - c->r_tmp);
  col_inc[2] = (c->col_ext.b - c->col_int.b) / (r_int - c->r_tmp);
  col_tmp[0] = c->col_ext.r;
  col_tmp[1] = c->col_ext.g;
  col_tmp[2] = c->col_ext.b;

  while (c->r_tmp >= r_int)
    {
      col_tmp[0] += col_inc[0];
      col_tmp[1] += col_inc[1];
      col_tmp[2] += col_inc[2];
      _andres(c, col_tmp);
      --c->r_tmp;
    }
}
