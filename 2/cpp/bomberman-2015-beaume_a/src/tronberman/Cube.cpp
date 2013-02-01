#include		<GL/gl.h>
#include		<GL/glu.h>
#include		"Cube.hpp"
#include		"setMateriel.hpp"

void			Cube::update(gdl::GameClock const& clock, gdl::Input&)
{
  this->_rot.update(clock.getTotalGameTime());
  this->_sca.update(clock.getTotalGameTime());
}

void			Cube::draw(void)
{
  this->_tex->bind();

  setMateriel(0.5f);

  glPushMatrix();
  glTranslatef(this->_pos.x() + .5, this->_pos.y() + .5, this->_pos.z());
  glScalef(this->_sca.x(), this->_sca.y(), this->_sca.z());
  glRotatef(this->_rot.z(), 0, 0, 1);

  // Sol
  glBegin(GL_TRIANGLE_STRIP);
  glTexCoord2f(1., 0); glNormal3i(0, 0, -1); glVertex3f(+.5, -.5, 0);
  glTexCoord2f(.5, 0); glNormal3i(0, 0, -1); glVertex3f(-.5, -.5, 0);
  glTexCoord2f(1., 1); glNormal3i(0, 0, -1); glVertex3f(+.5, +.5, 0);
  glTexCoord2f(.5, 1); glNormal3i(0, 0, -1); glVertex3f(-.5, +.5, 0);
  glEnd();

  // Plafond
  glBegin(GL_TRIANGLE_STRIP);
  glTexCoord2f(1., 0); glNormal3i(0, 0, 1); glVertex3f(+.5, +.5, 1);
  glTexCoord2f(.5, 0); glNormal3i(0, 0, 1); glVertex3f(-.5, +.5, 1);
  glTexCoord2f(1., 1); glNormal3i(0, 0, 1); glVertex3f(+.5, -.5, 1);
  glTexCoord2f(.5, 1); glNormal3i(0, 0, 1); glVertex3f(-.5, -.5, 1);
  glEnd();

  // Gauche
  glBegin(GL_TRIANGLE_STRIP);
  glTexCoord2f(.5, 0); glNormal3i(-1, 0, 0); glVertex3f(-.5, -.5, 1);
  glTexCoord2f(.0, 0); glNormal3i(-1, 0, 0); glVertex3f(-.5, +.5, 1);
  glTexCoord2f(.5, 1); glNormal3i(-1, 0, 0); glVertex3f(-.5, -.5, 0);
  glTexCoord2f(.0, 1); glNormal3i(-1, 0, 0); glVertex3f(-.5, +.5, 0);
  glEnd();

  // Droite
  glBegin(GL_TRIANGLE_STRIP);
  glTexCoord2f(.5, 0); glNormal3i(1, 0, 0); glVertex3f(+.5, +.5, 1);
  glTexCoord2f(.0, 0); glNormal3i(1, 0, 0); glVertex3f(+.5, -.5, 1);
  glTexCoord2f(.5, 1); glNormal3i(1, 0, 0); glVertex3f(+.5, +.5, 0);
  glTexCoord2f(.0, 1); glNormal3i(1, 0, 0); glVertex3f(+.5, -.5, 0);
  glEnd();

  // Devant
  glBegin(GL_TRIANGLE_STRIP);
  glTexCoord2f(.5, 0); glNormal3i(0, 1, 0); glVertex3f(-.5, +.5, 1);
  glTexCoord2f(.0, 0); glNormal3i(0, 1, 0); glVertex3f(+.5, +.5, 1);
  glTexCoord2f(.5, 1); glNormal3i(0, 1, 0); glVertex3f(-.5, +.5, 0);
  glTexCoord2f(.0, 1); glNormal3i(0, 1, 0); glVertex3f(+.5, +.5, 0);
  glEnd();

  // Derriere
  glBegin(GL_TRIANGLE_STRIP);
  glTexCoord2f(.5, 0); glNormal3i(0, -1, 0); glVertex3f(+.5, -.5, 1);
  glTexCoord2f(.0, 0); glNormal3i(0, -1, 0); glVertex3f(-.5, -.5, 1);
  glTexCoord2f(.5, 1); glNormal3i(0, -1, 0); glVertex3f(+.5, -.5, 0);
  glTexCoord2f(.0, 1); glNormal3i(0, -1, 0); glVertex3f(-.5, -.5, 0);
  glEnd();

  glPopMatrix();
}
