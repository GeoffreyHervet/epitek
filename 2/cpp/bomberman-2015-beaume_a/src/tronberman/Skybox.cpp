#include		<GL/gl.h>
#include		"Skybox.hpp"
#include		"setMateriel.hpp"

void			Skybox::update(gdl::GameClock const& clock, gdl::Input&)
{
  this->_rot.setA(0, 0, this->_rot.z() + 1 * clock.getElapsedTime());
}

void			Skybox::draw(void)
{
  glDisable(GL_LIGHTING);
  glDepthMask(GL_FALSE);

  this->_tex->bind();

  glPushMatrix();
  glScalef(500, 500, 500);
  glRotatef(this->_rot.z(), 0, 0, 1);
  glTranslatef(-.5, -.5, -.8);

  glColor3f(1, 1, 1);

  // Devant
  glBegin(GL_TRIANGLE_STRIP);
  glTexCoord2f(.50, 1/3.); glNormal3i(0, 1, 0); glVertex3i(1, 1, 1);
  glTexCoord2f(.25, 1/3.); glNormal3i(0, 1, 0); glVertex3i(0, 1, 1);
  glTexCoord2f(.50, 2/3.); glNormal3i(0, 1, 0); glVertex3i(1, 1, 0);
  glTexCoord2f(.25, 2/3.); glNormal3i(0, 1, 0); glVertex3i(0, 1, 0);
  glEnd();

  // Sol
  glBegin(GL_TRIANGLE_STRIP);
  glTexCoord2f(.50, 2/3.); glNormal3i(0, 0, -1); glVertex3i(1, 1, 0);
  glTexCoord2f(.25, 2/3.); glNormal3i(0, 0, -1); glVertex3i(0, 1, 0);
  glTexCoord2f(.50, 1.0); glNormal3i(0, 0, -1); glVertex3i(1, 0, 0);
  glTexCoord2f(.25, 1.0); glNormal3i(0, 0, -1); glVertex3i(0, 0, 0);
  glEnd();

  // Droite
  glBegin(GL_TRIANGLE_STRIP);
  glTexCoord2f(.75, 1/3.); glNormal3i(1, 0, 0); glVertex3i(1, 0, 1);
  glTexCoord2f(.50, 1/3.); glNormal3i(1, 0, 0); glVertex3i(1, 1, 1);
  glTexCoord2f(.75, 2/3.); glNormal3i(1, 0, 0); glVertex3i(1, 0, 0);
  glTexCoord2f(.50, 2/3.); glNormal3i(1, 0, 0); glVertex3i(1, 1, 0);
  glEnd();

  // Derriere
  glBegin(GL_TRIANGLE_STRIP);
  glTexCoord2f(1.0, 1/3.); glNormal3i(0, -1, 0); glVertex3i(0, 0, 1);
  glTexCoord2f(.75, 1/3.); glNormal3i(0, -1, 0); glVertex3i(1, 0, 1);
  glTexCoord2f(1.0, 2/3.); glNormal3i(0, -1, 0); glVertex3i(0, 0, 0);
  glTexCoord2f(.75, 2/3.); glNormal3i(0, -1, 0); glVertex3i(1, 0, 0);
  glEnd();

  // Gauche
  glBegin(GL_TRIANGLE_STRIP);
  glTexCoord2f(.25, 1/3.); glNormal3i(-1, 0, 0); glVertex3i(0, 1, 1);
  glTexCoord2f(.00, 1/3.); glNormal3i(-1, 0, 0); glVertex3i(0, 0, 1);
  glTexCoord2f(.25, 2/3.); glNormal3i(-1, 0, 0); glVertex3i(0, 1, 0);
  glTexCoord2f(.00, 2/3.); glNormal3i(-1, 0, 0); glVertex3i(0, 0, 0);
  glEnd();

  // Ciel
  glBegin(GL_TRIANGLE_STRIP);
  glTexCoord2f(.50, 1/3.); glNormal3i(0, 0, 1); glVertex3i(1, 1, 1);
  glTexCoord2f(.25, 1/3.); glNormal3i(0, 0, 1); glVertex3i(0, 1, 1);
  glTexCoord2f(.50, .00); glNormal3i(0, 0, 1); glVertex3i(1, 0, 1);
  glTexCoord2f(.25, .00); glNormal3i(0, 0, 1); glVertex3i(0, 0, 1);
  glEnd();

  glPopMatrix();

  glEnable(GL_LIGHTING);
  glDepthMask(GL_TRUE);
}
