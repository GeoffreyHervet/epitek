#include	"Document.hpp"

Document::Document(unsigned int width, unsigned int height, QWidget * parent, Qt::WindowFlags flags)
  : QWidget(parent, flags),
    _width(width),
    _height(height),
    _currentItem(0),
    _layout(new QHBoxLayout(this)),
    _view(new MapView(&_currentItem, width, height, this)),
    _listItem(new QListWidget(this))
{
  QListWidgetItem *	item;

  item = new QListWidgetItem(QPixmap("./res/img/map/ground.bmp").copy(64, 0, 64, 64), "Ground", this->_listItem);
  item->setData(Qt::UserRole, 0);
  this->_listItem->addItem(item);

  item = new QListWidgetItem(QPixmap("./res/img/map/box.bmp").copy(64, 0, 64, 64), "Box", this->_listItem);
  item->setData(Qt::UserRole, 1);
  this->_listItem->addItem(item);

  item = new QListWidgetItem(QPixmap("./res/img/map/ground.bmp").copy(64, 0, 64, 64), "Wall", this->_listItem);
  item->setData(Qt::UserRole, 2);
  this->_listItem->addItem(item);

  this->_listItem->setUniformItemSizes(true);
  this->_listItem->setFixedWidth(125);

  this->_layout->addWidget(this->_view);
  this->_layout->addWidget(this->_listItem);

  this->setLayout(this->_layout);

  connect(this->_listItem, SIGNAL(itemSelectionChanged()),
          this, SLOT(itemSelectionChanged()));

  this->_listItem->item(0)->setSelected(true);
}

MapView::Map const&	Document::getMap()
{
  return (this->_view->getMap());
}

void		Document::itemSelectionChanged()
{
  this->_currentItem = this->_listItem->selectedItems()[0]->data(Qt::UserRole).toUInt();
}
