#include	"NewFileDialog.hpp"

NewFileDialog::NewFileDialog(QWidget * parent, Qt::WindowFlags flags)
  : QDialog(parent, flags),
    _layout(new QGridLayout(this)),
    _send(new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, this)),
    _labelWidth(new QLabel("Width :", this, flags)),
    _inputWidth(new QLineEdit("50", this)),
    _labelHeight(new QLabel("Height : ", this, flags)),
    _inputHeight(new QLineEdit("50", this))
{
  this->_inputWidth->setValidator(new QRegExpValidator(QRegExp("^([1-9]|[1-9][0-9]|[1-9][0-9][0-9])$"), this->_inputWidth));
  this->_inputHeight->setValidator(new QRegExpValidator(QRegExp("^([1-9]|[1-9][0-9]|[1-9][0-9][0-9])$"), this->_inputHeight));

  this->_layout->addWidget(this->_labelWidth, 0, 0);
  this->_layout->addWidget(this->_inputWidth, 0, 1);
  this->_layout->addWidget(this->_labelHeight, 1, 0);
  this->_layout->addWidget(this->_inputHeight, 1, 1);
  this->_layout->addWidget(this->_send, 2, 0, 1, -1, Qt::AlignCenter);
  this->setLayout(this->_layout);

  connect(this->_send, SIGNAL(accepted()), this, SLOT(accept()));
  connect(this->_send, SIGNAL(rejected()), this, SLOT(reject()));
}

unsigned int	NewFileDialog::getWidth() const
{
  return (this->_inputWidth->text().toUInt());
}

unsigned int	NewFileDialog::getHeight() const
{
  return (this->_inputHeight->text().toUInt());
}
