#include	"MapView.hpp"

MapView::MapView(unsigned int const * currentItem, unsigned int width, unsigned int height, QWidget * parent)
  : QGraphicsView(parent),
    _width(width),
    _height(height),
    _currentItem(currentItem),
    _rubberBand(0),
    _scene(new QGraphicsScene(this))
{
  this->setScene(this->_scene);
  this->drawGrid();
}

MapView::Map const&	MapView::getMap()
{
  return (this->_map);
}

void		MapView::drawGrid()
{
  // GRID
  for (unsigned int x = 0; x <= this->_width; ++x)
    if (x == 0 || x == this->_width)
      this->_scene->addLine(x * 65, 0, x * 65, (this->_height * 65), QPen(Qt::black));
    else
      this->_scene->addLine(x * 65, 1, x * 65, (this->_height * 65) - 1, QPen(Qt::gray));
  for (unsigned int y = 0; y <= this->_height; ++y)
    if (y == 0 || y == this->_height)
      this->_scene->addLine(0, y * 65, (this->_width * 65), y * 65, QPen(Qt::black));
    else
      this->_scene->addLine(1, y * 65, (this->_width * 65) - 1, y * 65, QPen(Qt::gray));

  // EMPTYs
  for (unsigned int y = 0; y < this->_height; ++y)
    {
      this->_map.push_back(Line(this->_width));
      for (unsigned int x = 0; x < this->_width; ++x)
        this->addItem((x * 65) + 1, (y * 65) + 1);
    }
}

void		MapView::mousePressEvent(QMouseEvent * event)
{
  this->_origin = event->pos();
  if (!this->_rubberBand)
    this->_rubberBand = new QRubberBand(QRubberBand::Rectangle, this);
  this->_rubberBand->setGeometry(QRect(this->_origin, QSize()));
  this->_rubberBand->show();
}

void		MapView::mouseMoveEvent(QMouseEvent * event)
{
  this->_rubberBand->setGeometry(QRect(this->_origin, event->pos()).normalized());
}

void		MapView::mouseReleaseEvent(QMouseEvent * e)
{
  QPoint	event = this->mapToScene(e->pos()).toPoint();

  this->_rubberBand->hide();

  QList<QGraphicsItem *> list = this->_scene->items(this->mapToScene(QRect(this->_origin, e->pos()).normalized()));
  Q_FOREACH (QGraphicsItem * item, list)
    if (qgraphicsitem_cast<QGraphicsLineItem*>(item) == 0)
      {
        this->_map[(item->scenePos().y() - 1) / 65][(item->scenePos().x() - 1) / 65] = 0;
        this->_scene->removeItem(item);
      }

  if (e->pos() == this->_origin)
    {
      if (event.x() > 0 && event.y() > 0 && event.x() < ((int)this->_width * 65) && event.y() < ((int)this->_height * 65))
        this->addItem(event.x() - (event.x() % 65) + 1, event.y() - (event.y() % 65) + 1);
    }
  else
    {
      QPoint origin = this->mapToScene(this->_origin).toPoint();

      int beginx = (origin.x() < event.x()) ? (origin.x() - (origin.x() % 65) + 1) : (event.x() - (event.x() % 65) + 1);
      int beginy = (origin.y() < event.y()) ? (origin.y() - (origin.y() % 65) + 1) : (event.y() - (event.y() % 65) + 1);
      int endx = (origin.x() < event.x()) ? (event.x() - (event.x() % 65) + 1) : (origin.x() - (origin.x() % 65) + 1);
      int endy = (origin.y() < event.y()) ? (event.y() - (event.y() % 65) + 1) : (origin.y() - (origin.y() % 65) + 1);

      for (int y = beginy; y <= endy; y += 65)
        for (int x = beginx; x <= endx; x += 65)
          if (x > 0 && y > 0 && x < ((int)this->_width * 65) && y < ((int)this->_height * 65))
            this->addItem(x, y);
    }
}

void		MapView::addItem(int x, int y)
{
  QGraphicsPixmapItem *	item;

  if (*this->_currentItem == 1)
    item = new QGraphicsPixmapItem(QPixmap("./res/img/map/box.bmp").copy(64, 0, 64, 64));
  else if (*this->_currentItem == 2)
    item = new QGraphicsPixmapItem(QPixmap("./res/img/map/wall.bmp").copy(64, 0, 64, 64));
  else
    item = new QGraphicsPixmapItem(QPixmap("./res/img/map/ground.bmp").copy(64, 0, 64, 64));
  item->setPos(x, y);
  this->_scene->addItem(item);
  this->_map[(item->scenePos().y() - 1) / 65][(item->scenePos().x() - 1) / 65] = *this->_currentItem;
}
