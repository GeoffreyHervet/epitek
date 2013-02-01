#ifndef			MAPGRAPH_HPP
# define		MAPGRAPH_HPP

# include		<Image.hpp>
# include		"Cube.hpp"
# include		"Map.hpp"
# include		"Bombs.hpp"

class			MapGraph
{
  
public:

  MapGraph(void);

  Map const*			getMap(void) const;
  Cube const*			getCube(unsigned x, unsigned y) const;

  void				newMap(Map* map);
  void				update(gdl::GameClock const& clock,
				       gdl::Input& input);
  void				draw(void) const;
  void				putBomb(Bombs::Bomb*, double timeCurr,
					double duration);
  void				putGround(unsigned x, unsigned y,
					  double timeCurr);

private:

  void				opening(double time);

  gdl::Image			_tex[Map::UNKNOWN];
  Map*				_map;
  Cube*				_objs;
  Cube**			_tab;
  unsigned			_opening_h;
  double			_time;

};

#endif
