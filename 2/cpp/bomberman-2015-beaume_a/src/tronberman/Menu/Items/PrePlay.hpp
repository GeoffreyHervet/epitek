#ifndef PREPLAY_HPP_
# define PREPLAY_HPP_

# include	"AMenuObject.hpp"

namespace		Menu
{
  class			PrePlay : public AMenuObject
  {
    private:
      PrePlay(const PrePlay &);
      PrePlay &operator=(const PrePlay &);
    public:
      PrePlay(const std::string &);
      ~PrePlay();

      bool	 	selected(IMenu &, MyGame &, gdl::Input &);
  };
}

#endif /* PREPLAY_HPP_ */
