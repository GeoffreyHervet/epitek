#include		<GL/gl.h>
#include		"ParticlesEngine.hpp"

ParticlesEngine::ParticlesEngine(double x, double y, double z)
  : _pos(x, y, z), _dir(0, 0, 0)
{
  this->_power = 1;
}

void			ParticlesEngine::setDir(double x, double y, double z)
{
  this->_dir.init(x, y, z);
}

void			ParticlesEngine::newParticle(gdl::Image &tex, double time, double duration, bool loop)
{
  Particle*		p = new Particle(this->_pos, tex);

  p->setLife(time, duration, loop);
  this->_particles.push_back(p);
}

Particle*		ParticlesEngine::lastParticle(void)
{
  return this->_particles.back();
}

bool			ParticlesEngine::update(MapGraph const& map, double time)
{
  this->_it = this->_particles.begin();
  for (; this->_it != this->_particles.end(); ++this->_it)
    if ((*this->_it)->update(map, time))
      {
	this->_it = this->_particles.erase(this->_it);
	if (this->_particles.empty())
	  return true;
      }
  return false;
}

void			ParticlesEngine::draw(double theta, double phy)
{
  glDisable(GL_LIGHTING);
  this->_it = this->_particles.begin();
  for (; this->_it != this->_particles.end(); ++this->_it)
    (*this->_it)->draw(theta, phy);
  glColor4f(1, 1, 1, 1);
  glEnable(GL_LIGHTING);
}
