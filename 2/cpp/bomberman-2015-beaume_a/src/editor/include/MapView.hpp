#ifndef		MAPVIEW_HPP_
# define	MAPVIEW_HPP_

# include	<QtGui>

class		MapView : public QGraphicsView
{
  Q_OBJECT

  public:
    typedef	unsigned int	Cell;
    typedef	QVector<Cell>	Line;
    typedef	QVector<Line>	Map;

  public:
    MapView(unsigned int const * currentItem, unsigned int width, unsigned int height, QWidget * parent = 0);

  public:
    Map const&	getMap();

  private:
    void	drawGrid();
    void	addItem(int x, int y);
    void	mousePressEvent(QMouseEvent * event);
    void	mouseMoveEvent(QMouseEvent * event);
    void	mouseReleaseEvent(QMouseEvent *);

  private:
    unsigned int		_width;
    unsigned int		_height;
    unsigned int const *	_currentItem;
    Map				_map;

  private:
    QPoint		_origin;
    QRubberBand *	_rubberBand;

  private:
    QGraphicsScene *	_scene;
};

#endif	/*	!MAPVIEW_HPP_ */
