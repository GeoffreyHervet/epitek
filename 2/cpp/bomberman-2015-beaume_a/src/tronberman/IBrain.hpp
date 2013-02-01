#ifndef			IBRAIN_HPP
# define		IBRAIN_HPP

# include		<Input.hpp>

class			IBrain
{

public:

  enum			eAction
    {
      MOVE,
      ATTACK,
      WAIT,
      UNKNOWN
    };

  virtual ~IBrain(void) {}

  virtual eAction	action(gdl::Input&, int* x, int* y) = 0;

};

#endif
