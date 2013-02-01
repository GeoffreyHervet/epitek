#ifndef				BLASTS_HPP
# define			BLASTS_HPP

# include			<list>
# include			<vector>
# include			<Image.hpp>
# include			"ParticlesBlast.hpp"
# include			"MapGraph.hpp"

class				Blasts
{

public:

  enum				eTex
    {
      BLAST0,
      BLAST1,
      PARTICLE,
    };

  Blasts();
  ~Blasts();

  void				newBlast(int x, int y, double time);
  void				update(MapGraph const& map, double time);
  void				draw(double theta, double phy);

private:

  std::vector<gdl::Image>		_tex;
  std::list<ParticlesBlast*>		_blasts;
  std::list<ParticlesBlast*>::iterator	_it;

};

#endif
