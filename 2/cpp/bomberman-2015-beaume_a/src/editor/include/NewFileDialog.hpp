#ifndef		NEWFILEDIALOG_HPP_
# define	NEWFILEDIALOG_HPP_

# include	<QtGui>

class		NewFileDialog : public QDialog
{
  public:
    NewFileDialog(QWidget * parent = 0, Qt::WindowFlags flags = 0);

  public:
    unsigned int	getWidth() const;
    unsigned int	getHeight() const;

  private:
    QGridLayout *	_layout;
    QDialogButtonBox *	_send;
    // Width
    QLabel *		_labelWidth;
    QLineEdit *		_inputWidth;
    // Height
    QLabel *		_labelHeight;
    QLineEdit *		_inputHeight;
};

#endif	/*	!NEWFILEDIALOG_HPP_ */
