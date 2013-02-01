#include		<GL/gl.h>
#include		"Particle.hpp"
#include		"myMath.hpp"

Particle::Particle(myMath::Vect const& pos, gdl::Image &tex)
  : _tex(tex),
    _pos(pos),
    _dir(0, 0, 0),
    _alpha(1)
{
  this->_gravity = 0;
  this->_size = .2;
  this->_angVel = 0;
  this->_rotZ = rand() % 360;
  this->_frameCurr = 0;
  this->_nbFrames = tex.getWidth() / tex.getHeight();
  this->_incrX = 1. / this->_nbFrames;
  this->setAlpha(0);
}

void			Particle::setDir(myMath::Vect dir, double power) { this->_dir = dir * power; }
void			Particle::setSize(double size) { this->_size = size; }
void			Particle::setGravity(double gravity) { this->_gravity = gravity; }
void			Particle::setAngVel(double z) { this->_angVel = z; }
void			Particle::setAlpha(double a) { this->_alpha.setB(a, Interp::LINEAR); }

void			Particle::setRandom(double x, double y, double z)
{
  this->_dir.x += myMath::myFrand(-x, x);
  this->_dir.y += myMath::myFrand(-y, y);
  this->_dir.z += myMath::myFrand(-z, z);
}

void			Particle::setLife(double timeCurr, double duration, bool loop)
{
  this->_timeCurr = timeCurr;
  this->_timePrev = timeCurr;
  this->_timeDeath = timeCurr + duration;
  this->_loop = loop;
  this->_alpha.setDuration(timeCurr, duration);
}

void			Particle::draw(double ay, double az)
{
  this->_tex.bind();

  glPushMatrix();

  glTranslatef(this->_pos.x, this->_pos.y, this->_pos.z);
  glRotatef(az, 0, 0, 1);
  glRotatef(ay, 0, 1, 0);
  glRotatef(this->_rotZ, 0, 0, 1);
  glScalef(this->_size, this->_size, this->_size);

  glColor4f(1, 1, 1, this->_alpha.n());
  glBegin(GL_TRIANGLE_STRIP);
  glTexCoord2f((this->_frameCurr + 1) * this->_incrX, 0); glNormal3i(0, 0, 1); glVertex3f(+.5, +.5, 0);
  glTexCoord2f((this->_frameCurr + 0) * this->_incrX, 0); glNormal3i(0, 0, 1); glVertex3f(-.5, +.5, 0);
  glTexCoord2f((this->_frameCurr + 1) * this->_incrX, 1); glNormal3i(0, 0, 1); glVertex3f(+.5, -.5, 0);
  glTexCoord2f((this->_frameCurr + 0) * this->_incrX, 1); glNormal3i(0, 0, 1); glVertex3f(-.5, -.5, 0);
  glEnd();

  glPopMatrix();
}

bool			Particle::update(MapGraph const& map, double time)
{
  Cube const*		cube;
  Cube const*		cubeCurr;

  if (this->_timeCurr > this->_timeDeath)
    return true;

  this->_timeCurr += time;
  this->_rotZ += this->_angVel * time;
  this->_dir.z -= this->_gravity * time;
  this->_alpha.update(this->_timeCurr);

  cubeCurr = this->_pos.x < 0 || this->_pos.y < 0 ?
    NULL : map.getCube(this->_pos.x, this->_pos.y);

  // X
  cube = map.getCube(this->_pos.x + this->_dir.x * time, this->_pos.y);
  if (cube && cube != cubeCurr && this->_pos.z + this->_dir.z * time < cube->getScaleZ())
    this->_dir.x *= -1;
  else
    this->_pos.x += this->_dir.x * time;

  // Y
  cube = map.getCube(this->_pos.x, this->_pos.y + this->_dir.y * time);
  if (cube && cube != cubeCurr && this->_pos.z + this->_dir.z * time < cube->getScaleZ())
    this->_dir.y *= -1;
  else
    this->_pos.y += this->_dir.y * time;
    
  // Z
  if (cubeCurr && this->_dir.z < 0 && this->_pos.z + this->_dir.z * time < cubeCurr->getScaleZ())
    {
      this->_dir.z /= -2;
      this->_dir.x /= 2;
      this->_dir.y /= 2;
    }
  else
    this->_pos.z += this->_dir.z * time;

  // frames
  if (this->_timeCurr > this->_timePrev + .04)
    {
      this->_timePrev = this->_timeCurr;
      if (this->_frameCurr < this->_nbFrames - 1)
	++this->_frameCurr;
      else if (this->_loop)
	this->_frameCurr = 0;
    }

  return false;
}
