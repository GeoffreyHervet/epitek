#include		"Lights.hpp"

void			Lights::initialize(void)
{
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_COLOR_MATERIAL);

  glColorMaterial(GL_AMBIENT_AND_DIFFUSE, GL_EMISSION);
  glMateriali(GL_FRONT, GL_SHININESS, 1);

  for (unsigned u = 0; u < NB_LIGHTS; ++u)
    {
      this->_pos[u][3] = 1.0;
      this->_amb[u][3] = 1.0;
      this->_dif[u][3] = 1.0;
      this->setAmb(u, 1, 1, 1);
      this->setDif(u, 1, 1, 1);
      this->setPos(u, 0, 0, 2.0);
    }

  glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, .05);
}

void			Lights::update(gdl::GameClock const&, gdl::Input&)
{
  static double		a;

  a += 0.1;
  this->setPos(0, sin(a) * 3 + 5.5, cos(a) * 3 + 5.5, 1.);
}
