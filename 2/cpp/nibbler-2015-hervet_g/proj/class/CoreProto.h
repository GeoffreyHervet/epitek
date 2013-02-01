#ifndef COREPROTO_H_
# define COREPROTO_H_

# include <iostream>

namespace	Nibbler
{
  typedef enum
  {
    UNKNOWN,
    MV_LEFT,
    MV_RIGHT,
    MV_UP,
    MV_DOWN,
    PAUSE,
    EXIT
  }	eEvent;

  typedef enum
  {
    NORMAL
  }	eFoodType;

  typedef struct
  {
    unsigned char	y;
    unsigned char	x;
    eFoodType		type;
  }			tFood;

  class Core;
};

#endif /* COREPROTO_H_ */
