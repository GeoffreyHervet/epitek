#include		<GL/gl.h>

void			setMateriel(GLfloat r, GLfloat g, GLfloat b)
{
  GLfloat		tab[4];

  tab[0] = r;
  tab[1] = g;
  tab[2] = b;
  tab[3] = 1.0;
  glMaterialfv(GL_FRONT, GL_AMBIENT, tab);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, tab);
}

void			setMateriel(GLfloat gray)
{
  setMateriel(gray, gray, gray);
}

void			setMateriel(int r, int g, int b)
{
  setMateriel(r / 255.f, g / 255.f, b / 255.f);
}

void			setMateriel(int gray)
{
  setMateriel(gray, gray, gray);
}
