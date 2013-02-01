#ifndef RESUME_HPP_
# define RESUME_HPP_

namespace	Menu {
  class		Resume;
}

# include	"AMenuObject.hpp"

namespace	Menu
{
  class		Resume : public AMenuObject
  {
    private:
      Resume(const Resume &);
      Resume &operator=(const Resume &);

    public:
      Resume(const std::string &);
      ~Resume();

      bool	 	selected(IMenu &, MyGame &, gdl::Input &);
  };
}

#endif /* RESUME_HPP_ */
