# include		"ParticlesBlast.hpp"

ParticlesBlast::ParticlesBlast(int x, int y, double time, std::vector<gdl::Image> &tex)
  : ParticlesEngine(x + .5, y + .5, .7)
{
  this->_dir.init(0, 0, 1);
  this->newParticle(tex[0], time, 1, false);
  this->lastParticle()->setSize(3.);
  this->lastParticle()->setAlpha(.25);
  for (unsigned u = 0; u < 10; ++u)
    {
      this->newParticle(tex[2], time, 10, false);
      this->lastParticle()->setSize(.2);
      this->lastParticle()->setAlpha(0.);
      this->lastParticle()->setDir(this->_dir, 5);
      this->lastParticle()->setRandom(1, 1, 4);
      this->lastParticle()->setGravity(10);
    }
}
