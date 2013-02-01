#ifndef			BOMBS_HPP
# define		BOMBS_HPP

# include		<list>

# include		"ISoundManager.hpp"

class			Player;
class			MapGraph;
class			MyGame;
class			Bomb;

# define		TIMEMAX	4000000

class			Bombs
{

public:
  Bombs();
  ~Bombs(){};

  struct		Bomb
  {
    Player*		player;
    unsigned		x, y;
    unsigned		power;
    unsigned		exploding;
    bool		dir[4];
    double		timePrev;
    double		timeToExplode;
    double		timeLeft;
  };

  void			putBomb(MapGraph&, Player&, double timeCurr, double duration);
  void			update(MyGame& game);

  std::list<Bomb*> const	&getBombList(void) const { return _bombs; }

  void			wait(double);
  void			setSoundManager(ISoundManager *sm) { this->_sm = sm; };

private:

  ISoundManager		*_sm;
  std::list<Bomb*>	_bombs;

  Bomb*			getBomb(unsigned x, unsigned y);
  void			propagateBomb(MyGame&, Bomb*);
  void			killPlayer(MyGame&, Bomb*, unsigned x, unsigned y);

  class			Waiter
  {
    public:
      Waiter(double t): _t(t) {};
      ~Waiter(){};
      void		operator()(Bomb *b) { b->timeLeft += this->_t; b->timeToExplode += this->_t;};
    private:
      double _t;
  };

};

#endif
