#ifndef			PARTICLE_HPP
# define		PARTICLE_HPP

# include		<Image.hpp>
# include		<stdlib.h>
# include		"MapGraph.hpp"
# include		"myMath.hpp"
# include		"Interp.hpp"

class			Particle
{

public:

  Particle(myMath::Vect const& pos, gdl::Image &tex);
  ~Particle(){};

  void			draw(double ay, double az);
  bool			update(MapGraph const& map, double time);

  void			setDir(myMath::Vect dir, double power);
  void			setSize(double size);
  void			setGravity(double gravity);
  void			setAngVel(double z);
  void			setAlpha(double a);
  void			setRandom(double x, double y, double z);
  void			setLife(double timeCurr, double duration, bool loop);

private:
  gdl::Image&		_tex;
  myMath::Vect		_pos;
  myMath::Vect		_dir;
  Interp		_alpha;
  double		_rotZ;
  double		_angVel;
  double		_size;
  double		_gravity;
  double		_timePrev;
  double		_timeCurr;
  double		_timeDeath;

  bool			_loop;
  unsigned		_nbFrames;
  unsigned		_frameCurr;
  double		_incrX;

};

#endif
