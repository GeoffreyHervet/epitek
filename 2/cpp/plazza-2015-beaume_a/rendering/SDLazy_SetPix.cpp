#include			<SDL/SDL.h>

void				SDLazy_SetPix(SDL_Surface *srf, int x, int y, Uint32 px)
{
  int				bpp = srf->format->BytesPerPixel;
  Uint8*			p = (Uint8*)srf->pixels + y * srf->pitch + x * bpp;

  switch (bpp)
    {
    case 1: *p = px; break;
    case 2: *(Uint16 *)p = px; break;
    case 4: *(Uint32 *)p = px; break;
    case 3:
      if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
	{
	  p[0] = (px >> 16) & 0xff;
	  p[1] = (px >> 8) & 0xff;
	  p[2] = px & 0xff;
	}
      else
	{
	  p[0] = px & 0xff;
	  p[1] = (px >> 8) & 0xff;
	  p[2] = (px >> 16) & 0xff;
	}
    }
}

void				SDLazy_SetPix_Secure(SDL_Surface *srf, int x, int y, Uint32 px)
{
  if (x >= 0 && x < srf->w && y >= 0 && y < srf->h)
    SDLazy_SetPix(srf, x, y, px);
}
