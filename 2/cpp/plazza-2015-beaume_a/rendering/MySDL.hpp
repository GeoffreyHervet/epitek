
#ifndef				MYSDL_HPP
#define				MYSDL_HPP

#include			<iostream>
#include			<cmath>
#include			<SDL/SDL.h>
#include			"Kitchen.hpp"
#include			"SDLazy_Circle.h"

class				MySDL
{
  
  Uint32			m_flags;
  SDL_Surface*			m_scr;
  double			m_zoom;
  double			m_x, m_y;
  bool				m_dragging;
  SDLazy_Circle			m_cir;
  double			m_frametime;

  void				setFrameTime(void)
  {
    static Uint32		ticks;
    Uint32			tmp = ticks;

    ticks = SDL_GetTicks();
    this->m_frametime = (ticks - tmp) / 1000.0;
  }

  void				drawKitchen(Kitchen const& k)
  {
    this->m_cir.srf = this->m_scr;
    this->m_cir.col_int.r = 12;
    this->m_cir.col_int.g = 12;
    this->m_cir.col_int.b = 33;
    this->m_cir.col_ext.r = 5;
    this->m_cir.col_ext.g = 5;
    this->m_cir.col_ext.b = 13;
    this->m_cir.x = this->m_x + k.getPosX() * this->m_zoom;
    this->m_cir.y = this->m_y + k.getPosY() * this->m_zoom;
    this->m_cir.r = (k.getRayon() + KITCHEN_RAY) * this->m_zoom;
    this->m_cir.border_size = -this->m_cir.r;
    this->m_cir.full_circle = 1;
    SDLazy_DrawCircle(&this->m_cir);
    this->drawIngrs(k);
  }

  void				drawIngrs(Kitchen const& k)
  {
    static double		a;
    double			d = 2 * M_PI / k.getNbIngrs();
    double			max = 0;

    a += .5 * this->m_frametime;
    this->m_cir.r += 6;
    this->m_cir.border_size = 10 * this->m_zoom;
    SDLazy_DrawCircle(&this->m_cir);
    this->m_cir.full_circle = 0;
    this->m_cir.col_ext.r = 5;
    this->m_cir.col_ext.g = 5;
    this->m_cir.col_ext.b = 5;
    for (unsigned i = 0; i < k.getNbIngrs(); ++i)
      if (k.getIngr(i) > max)
	max = k.getIngr(i);
    for (unsigned i = 0; i < k.getNbIngrs(); ++i)
      {
	this->m_cir.col_int.r = 0 + 50 * i;
	this->m_cir.col_int.g = 50 + 50 * i;
	this->m_cir.col_int.b = 100 + 50 * i;
	this->m_cir.deg[0] = a + d * i;
	this->m_cir.deg[1] = this->m_cir.deg[0] + d * (k.getIngr(i) / max);
	SDLazy_DrawCircle(&this->m_cir);
      }
    this->drawCooks(k);
  }

  void				drawCooks(Kitchen const& k)
  {
    this->m_cir.full_circle = 1;
    this->m_cir.col_int.r = 4;
    this->m_cir.col_int.g = 191;
    this->m_cir.col_int.b = 191;
    this->m_cir.col_ext.r = 3;
    this->m_cir.col_ext.g = 125;
    this->m_cir.col_ext.b = 125;
    this->m_cir.r = RAY_COOK * this->m_zoom;
    this->m_cir.border_size = -this->m_cir.r;
    for (unsigned i = 0; i < k.getNbCooks(); ++i)
      {
	this->m_cir.x = this->m_x + k.getPosX() + cos(k.getCook(i).getRad()) * k.getCook(i).getDist() * this->m_zoom;
	this->m_cir.y = this->m_y + k.getPosY() + sin(k.getCook(i).getRad()) * k.getCook(i).getDist() * this->m_zoom;
	SDLazy_DrawCircle(&this->m_cir);
      }
  }

public:

  MySDL(int w, int h, Uint32 flags)
  {
    if (SDL_Init(SDL_INIT_VIDEO) == -1)
      std::cerr << "SDL_Init failed: " << SDL_GetError() << "\n";
    else if (!(this->m_scr = SDL_SetVideoMode(w, h, 32, flags)))
      std::cerr << "SDL_SetVideoMode failed: " << SDL_GetError() << "\n";
    else
      {
	this->m_zoom = 1.0;
	this->m_x = this->m_scr->w / 2.0;
	this->m_y = this->m_scr->h / 2.0;
	this->m_flags = flags;
	this->m_dragging = false;
	return;
      }
    quit();
  }

  double			getFrametime(void) const { return this->m_frametime; }

  void				events(void)
  {
    SDL_Event			e;

    while (SDL_PollEvent(&e))
      switch (e.type)
	{
	case SDL_QUIT: this->quit(); break;
	case SDL_VIDEORESIZE:
	  if (!(this->m_scr = SDL_SetVideoMode(e.resize.w, e.resize.h, 32, this->m_flags)))
	    this->quit();
	  break;
	case SDL_KEYDOWN:
	  if (e.key.keysym.sym == SDLK_ESCAPE)
	    this->quit();
	  break;
	case SDL_MOUSEBUTTONDOWN:
	  if (e.button.button == SDL_BUTTON_WHEELUP)
	    this->m_zoom *= 1.1;
	  else if (e.button.button == SDL_BUTTON_WHEELDOWN)
	    this->m_zoom /= 1.1;
	  else if (e.button.button == SDL_BUTTON_LEFT)
	    this->m_dragging = true;
	  break;
	case SDL_MOUSEBUTTONUP:
	  if (e.button.button == SDL_BUTTON_LEFT)
	    this->m_dragging = false;
	  break;
	case SDL_MOUSEMOTION:
	  if (this->m_dragging)
	    {
	      this->m_x += e.motion.xrel;
	      this->m_y += e.motion.yrel;
	    }
	  break;
	}
  }

  void				render(Kitchen const& k)
  {
    this->setFrameTime();

    SDL_FillRect(this->m_scr, NULL, 0);

    this->drawKitchen(k);

    SDL_Flip(this->m_scr);
  }

  void				quit(void)
  {
    SDL_Quit();
    exit(0);
  }

};

#endif

