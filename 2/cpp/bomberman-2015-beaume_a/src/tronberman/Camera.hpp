#ifndef		CAMERA_HPP
# define	CAMERA_HPP

# include	<cmath>
# include	<GameClock.hpp>
# include	<Input.hpp>
# include	<Text.hpp>

# include	"InterpVect.hpp"
# include	"Map.hpp"
# include	"ISoundManager.hpp"

class		Camera
{

public:

  Camera(bool &);

  void		update(gdl::GameClock const&, gdl::Input&);
  void		draw(void);

  double	getThetaDeg(void) const;
  double	getPhyDeg(void) const;
  void		centerToMap(Map* map, double time);
  void		shake(double intensity);
  void		setPos(double r, double theta, double phy, double time);
  void		init(void);
  void		setSoundManager(ISoundManager *sm) { this->_sm = sm; };
  void		showCounter(void);

private:

  bool		&_intro;
  ISoundManager	*_sm;
  InterpVect	_sph;
  InterpVect	_target;
  gdl::Text	_txt;
  double	_shakeZ;
  int		_x_rel;
  int		_y_rel;
  bool		_left_clic;
  double	_counter;
};

#endif
