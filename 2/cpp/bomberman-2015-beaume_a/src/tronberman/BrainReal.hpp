#ifndef			BRAINREAL_HPP
# define		BRAINREAL_HPP

# include		"IBrain.hpp"

class			BrainReal : public IBrain
{

public:

  enum			key
    {
      UP, RIGHT, DOWN, LEFT, BOMB, NB_KEYS
    };
  
  BrainReal(gdl::Keys::Key tab[]);

  virtual eAction	action(gdl::Input&, int* x, int* y);

private:

  gdl::Keys::Key	_key[NB_KEYS];

};

#endif
