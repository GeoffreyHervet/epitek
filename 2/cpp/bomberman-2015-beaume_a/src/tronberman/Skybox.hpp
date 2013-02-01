#ifndef			SKYBOX_HPP
# define		SKYBOX_HPP

# include		"AObject.hpp"

class			Skybox : public AObject
{

public:

  Skybox(void)
  {
    this->_tex = new gdl::Image;
    *this->_tex = gdl::Image::load("res/img/skybox/0.png");
  }

  virtual void update(gdl::GameClock const&, gdl::Input&);
  virtual void draw(void);
  
};

#endif
