#include		<iostream>
#include		<GL/gl.h>
#include		<GL/glu.h>

#include		"Error.hpp"
#include		"Camera.hpp"
#include		"myMath.hpp"

Camera::Camera(bool &p) :
  _intro(p),
  _sm(0),
  _sph(10, 1.57, -1.57),
  _target(0, 0, 0),
  _txt("./res/font/DisplayOTF.otf")
{
  this->_shakeZ = 0;
  this->_x_rel = 0;
  this->_y_rel = 0;
  this->_left_clic = false;
  this->_counter = -1;
  this->_txt.setSize(100);
}

double		Camera::getThetaDeg(void) const
{
  return this->_sph.y() * 180 / M_PI;
}

double		Camera::getPhyDeg(void) const
{
  return this->_sph.z() * 180 / M_PI;
}

void		Camera::shake(double intensity)
{
  this->_shakeZ = intensity + fabs(this->_shakeZ);
}

void		Camera::centerToMap(Map* map, double time)
{
  this->_target.setA(map->getW() / 2. - .5, map->getH() / 2. + .5, 0);
  this->_sph.setA(0, 0, 0);
  this->_sph.setB(std::max(map->getW(), map->getH()), .7, -1.57, Interp::EASE_OUT);
  this->_sph.setDuration(time, 3);

  if (this->_sm != 0)
  {
    this->_counter = 3;
    try { this->_sm->playSound("./res/sounds/321go.mp3", 0, 100); }
    catch (const ::Error &e) { if (e.level() == Error::CRITICAL) throw; std::cerr << "[" << e.level() << "] " << e.what() << std::endl; }
  }
}

void		Camera::setPos(double r, double theta, double phy, double time)
{
  this->_sph.setB(r, theta, phy, Interp::EASE_OUT);
  this->_sph.setDuration(time, 3);
}

void		Camera::update(gdl::GameClock const& clock, gdl::Input& input)
{
  int		t, p;

  if (this->_intro && !this->_sph.isMoving())
  {
    this->_intro = false;
  }
  else if (this->_counter > -1)
    this->_counter -= clock.getElapsedTime();
  t = this->_y_rel - input.getMousePositionY();
  p = this->_x_rel - input.getMousePositionX();
  if (myMath::myFmod(this->_sph.y(), 2 * M_PI) > M_PI)
    p = -p;

  if (!this->_intro && input.isMouseButtonDown(gdl::Mouse::Right))
    {
      if (this->_y_rel - input.getMousePositionY() > 0)
	this->_sph.incrA(this->_sph.x() * -.05, 0, 0);
      else if (this->_y_rel - input.getMousePositionY() < 0)
	this->_sph.incrA(this->_sph.x() * .05, 0, 0);
    } 

  if (!this->_intro && input.isMouseButtonDown(gdl::Mouse::Left))
    this->_sph.incrA(0, t / 300., p / 300.);
  else if (!this->_intro && this->_left_clic)
    {
      this->_sph.incrB(0, t / 20.0, p / 20.0, Interp::EASE_OUT);
      this->_sph.setDuration(clock.getTotalGameTime(), .5);
    }

  this->_left_clic = (!this->_intro && input.isMouseButtonDown(gdl::Mouse::Left));

  this->_x_rel = input.getMousePositionX();
  this->_y_rel = input.getMousePositionY(); 

  this->_sph.update(clock.getTotalGameTime());
  this->_target.update(clock.getTotalGameTime());

  this->_shakeZ /= -1.2;
}

void		Camera::showCounter()
{
  if (this->_counter < -1)
    return;
  glLoadIdentity();
  gluOrtho2D(0.0, 1200, 0.0, 675);
  glDisable(GL_DEPTH_TEST);
  glDisable(GL_LIGHTING);

  if (this->_counter > 0)
    this->_txt.setPosition(580, 250);
  else
    this->_txt.setPosition(550, 250);
  if (this->_counter > 2) this->_txt.setText("3");
  else if (this->_counter > 1) this->_txt.setText("2");
  else if (this->_counter > 0) this->_txt.setText("1");
  else			  this->_txt.setText("Go");

  this->_txt.draw();

  this->init();
}

void		Camera::draw(void)
{
  myMath::Vect	_pos;

  _pos.x = this->_target.x() + this->_sph.x() * sin(this->_sph.y()) * cos(this->_sph.z());
  _pos.y = this->_target.y() + this->_sph.x() * sin(this->_sph.y()) * sin(this->_sph.z());
  _pos.z = this->_target.z() + this->_sph.x() * cos(this->_sph.y());

  gluLookAt(_pos.x,
	    _pos.y,
	    _pos.z + this->_shakeZ,
	    
            _target.x(),
	    _target.y(),
	    _target.z() + this->_shakeZ,

            0,
	    0,
	    myMath::myFmod(this->_sph.y(), 2 * M_PI) < M_PI ? 1 : -1
	    );
}

void		Camera::init(void)
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(70.0f, 16/9., 0.2f, 1000);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glShadeModel(GL_SMOOTH);
  glAlphaFunc(GL_GREATER, .1);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_LIGHTING);
  glEnable(GL_ALPHA_TEST);
}
