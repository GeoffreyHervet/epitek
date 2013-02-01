#ifndef			BRAINIA_HPP
# define		BRAINIA_HPP

# include		<list>
# include		<vector>
# include		"Map.hpp"
# include		"Bombs.hpp"
# include		"IBrain.hpp"
# include		"Players.hpp"
# include		"Map.hpp"

class			BrainIA : public IBrain
{

public:
  
  BrainIA(Map* map, Bombs& bombs, Players& players, Player* self);
  virtual ~BrainIA() {}

  virtual IBrain::eAction	action(gdl::Input&, int* x, int* y);

private:

  enum eMovement
    {
      UP,
      DOWN,
      RIGHT,
      LEFT,
      WAIT,
      ATTACK,
      UNKNOWN
    };

  typedef struct	s_coord
  {
    unsigned int	x;
    unsigned int	y;
    unsigned int	weigth;
  }			t_coord;

  void			findPath(void);
  void			fillTmpMap(void);
  void			addToDangerMap(unsigned int x, unsigned int y,
				       unsigned int power);
  void			fillDangerMap(void);
  void			PropageDangerousZone(unsigned int x, unsigned int y,
					     int px, int py,
					     unsigned int power,
					     double dif);
  bool			amIInDanger(void);
  void			putWeigth(int dangerosity,
				  unsigned int x,
				  unsigned int y,
				  int weigth);
  void			putWeigthRec(int dangerosity,
				     unsigned int x,
				     unsigned int y,
				     int weigth);
  void			buildBestPath(void);
  void			getReversePath(unsigned int x,
				       unsigned int y,
				       eMovement move);
  IBrain::eAction	convertAction(eMovement m, int *x, int *y);
  void			Defensive(void);

  bool			isReachDirection(unsigned int x, unsigned int y,
					 int px, int py, unsigned int power,
					 Map::eMap type);
  bool			isReach(unsigned int x, unsigned int y,
				unsigned int power, Map::eMap type);
  inline bool		thereIsanEscape();
  bool			putWeigthCompleteRec(int dangerosity,
					     unsigned int x,
					     unsigned int y,
					     int weigth,
					     int max);
  void			putWeigthComplete(int dangerosity,
					  unsigned int x,
					  unsigned int y,
					  int weigth,
					  int max);
  bool			tryToPutBomb(void);
  bool			checkPath(void);
  void			SelectObjective(void);
  bool			isReachPlayer(unsigned int x, unsigned int y,
				      unsigned int power);
  bool			isReachPlayerDirection(unsigned int x,
					       unsigned int y,
					       int px, int py,
					       unsigned int power);
  bool			CheckNextMove(int *x, int *y);
  void			Offensive(void);


  void		displayMap(void);

private:

  Map		*_map;
  Bombs		&_bombs;
  Players	&_players;
  Player	*_self;
  unsigned int	_w;
  unsigned int	_h;

  std::list<t_coord>		_possibilities;
  t_coord			_tmpCoord;

  std::list<enum eMovement>	_path;
  std::vector<Map::eMap>	_tmpMap;
  std::vector<int>		_pathMap;
  std::vector<double>		_dangerMap;
};

#endif
