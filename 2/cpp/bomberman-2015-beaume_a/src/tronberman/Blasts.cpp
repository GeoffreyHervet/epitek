#include	"Blasts.hpp"

Blasts::Blasts() :
  _tex(3)
{
  this->_tex[Blasts::BLAST0] = gdl::Image::load("res/img/particles/blast0.png");
  this->_tex[Blasts::BLAST1] = gdl::Image::load("res/img/particles/blast1.png");
  this->_tex[Blasts::PARTICLE] = gdl::Image::load("res/img/particles/particle.png");
}

Blasts::~Blasts()
{
}

void				Blasts::newBlast(int x, int y, double time)
{
  this->_blasts.push_front(new ParticlesBlast(x, y, time, this->_tex));
}

void				Blasts::update(MapGraph const& map, double time)
{
  this->_it = this->_blasts.begin();
  for (; this->_it != this->_blasts.end(); ++this->_it)
    if ((*this->_it)->update(map, time))
      this->_it = this->_blasts.erase(this->_it);
}

void				Blasts::draw(double theta, double phy)
{
  this->_it = this->_blasts.begin();
  for (; this->_it != this->_blasts.end(); ++this->_it)
    (*this->_it)->draw(theta, phy);
}

