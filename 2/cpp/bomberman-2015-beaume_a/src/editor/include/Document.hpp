#ifndef		DOCUMENT_HPP_
# define	DOCUMENT_HPP_

# include	<QtGui>
# include	"MapView.hpp"

class		Document : public QWidget
{
  Q_OBJECT

  public:
    Document(unsigned int width, unsigned int height, QWidget * parent = 0, Qt::WindowFlags flags = 0);

  public:
    MapView::Map const&	getMap();
    unsigned int	getMapWidth() const { return this->_width; };
    unsigned int	getMapHeight() const { return this->_height; };

  public slots:
    void		itemSelectionChanged();

  private:
    unsigned int	_width;
    unsigned int	_height;
    unsigned int	_currentItem;

  private:
    // Central
    QHBoxLayout *	_layout;
    // Map
    MapView *		_view;
    // Items list
    QListWidget *	_listItem;
};

#endif	/*	!DOCUMENT_HPP_ */
