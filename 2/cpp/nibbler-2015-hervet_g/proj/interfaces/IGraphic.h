#ifndef IGRAPHIC_H_
# define IGRAPHIC_H_

# include <deque>
# include <utility>
# include <vector>

# include "CoreProto.h"

namespace	Nibbler
{
  class IGraphic
  {
    public:
    virtual ~IGraphic() {};

    virtual eEvent getEvent() = 0;
    // virtual bool reset_queue(std::deque<std::pair<unsigned char,unsigned char> > &) = 0;
    virtual bool reset_queue(unsigned char, unsigned char) = 0;
    virtual bool displaySnake(std::deque<std::pair<unsigned char,unsigned char> > const &, Nibbler::eEvent) = 0;
    virtual bool displayMap(const std::vector<std::vector<bool> > &) = 0;
    virtual bool displayFood(const std::vector<tFood> &) = 0;
    virtual bool displayScore(unsigned int score) = 0;
  };
};

#endif /* IGRAPHIC_H_ */
