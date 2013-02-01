#ifndef			PARTICLESBLAST_HPP
# define		PARTICLESBLAST_HPP

# include		<vector>
# include		<Image.hpp>
# include		"ParticlesEngine.hpp"

class			ParticlesBlast : public ParticlesEngine
{
  public:
    ParticlesBlast(int x, int y, double time, std::vector<gdl::Image> &tex);
    ~ParticlesBlast();
};

#endif
