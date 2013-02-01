#ifndef			PARTICLESENGINE_HPP
# define		PARTICLESENGINE_HPP

# include		<list>
# include		<Image.hpp>
# include		"myMath.hpp"
# include		"Particle.hpp"
# include		"MapGraph.hpp"

class			ParticlesEngine
{
  
public:

  ParticlesEngine(double x, double y, double z);

  bool			update(MapGraph const& map, double time);
  void			draw(double theta, double phy);

  void			newParticle(gdl::Image &tex, double time, double duration, bool loop);
  Particle*		lastParticle(void);
  void			setDir(double x, double y, double z);

protected:

  myMath::Vect				_pos;
  myMath::Vect				_dir;
  double				_power;

private:

  std::list<Particle*>			_particles;
  std::list<Particle*>::iterator	_it;

};

#endif
