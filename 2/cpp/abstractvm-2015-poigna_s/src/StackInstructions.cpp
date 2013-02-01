#include	<iostream>
#include	<string>
#include	<sys/types.h>
#include	<deque>
#include	<map>

#include	"IOperand.hh"
#include	"Operands.hh"
#include	"Stack.hh"

namespace avm
{
  void            Stack::push(IOperand *val)
  {
    this->_val.push_front(val);
  }

  void            Stack::pop()
  {
    if (this->_val.empty())
      throw Stack::Error("Double without dec");
    delete this->_val.front();
    this->_val.pop_front();
  }

  /* Display all values on the stack */
  void            Stack::dump()
  {
    for (std::deque<IOperand *>::iterator iter = this->_val.begin() ; iter != this->_val.end() ; ++iter)
      std::cout << (*iter)->toString() << std::endl;
  }

  /* Sommet de la pile egale a celle passee en parametre? */
  void            Stack::assert(IOperand *val)
  {
    try
    {
      if (this->_val.size() < 1)
        throw Stack::Error("Empty Stack!");

      if (val->getPrecision() != this->_val.front()->getPrecision() ||
          val->toString() != this->_val.front()->toString())
      {
        double	tmp, tmp2;
        std::stringstream	topValue(this->_val.front()->toString());
        std::stringstream	tmpValue(val->toString());

        topValue >> tmp;
        tmpValue >> tmp2;
        /* et la var pipi et ben elle fait pipi sur le caca */
        if (tmp != tmp2)
          throw Stack::Error("Assert Fail");
      }
    }
    catch (...)
    {
      delete val;
      throw;
    }
    delete val;
  }

  void            Stack::add()
  {
    this->doOperation(ADD);
  }

  void            Stack::sub()
  {
    this->doOperation(SUB);
  }

  void            Stack::mul()
  {
    this->doOperation(MUL);
  }

  void		Stack::div()
  {
    this->doOperation(DIV);
  }

  void            Stack::mod()
  {
    this->doOperation(MODULO);
  }

  /* Valeur au sommet de la pile est un entier de 8 bits?
     L'interprete comme une valeur ascii et affiche le char
     sur la sortie standard */
  void            Stack::print()
  {
    if (this->_val.size() < 1)
      throw Stack::Error("Empty stack! Can't print!");

    if (this->_val.front()->getType() != INT8)
      throw Stack::Error("Top of stack is not Int8");

    std::stringstream     ss(this->_val.front()->toString());
    short                 tmp;
    char                  c;

    ss >> tmp;
    c = tmp;
    std::cout << c << std::endl;
  }

  void		Stack::doOperation(const eOperationType op)
  {
    if (this->_val.size() < 2)
      throw Stack::Error("You try to an operation without two values in your stack");

    IOperand      *v1 = this->_val.front();
    this->_val.pop_front();

    IOperand      *v2 = this->_val.front();
    this->_val.pop_front();

    switch (op)
    {
      case ADD: this->_val.push_front(*v2 + *v1); break;
      case SUB: this->_val.push_front(*v2 - *v1); break;
      case MUL: this->_val.push_front(*v2 * *v1); break;
      case DIV: this->_val.push_front(*v2 / *v1); break;
      case MODULO: this->_val.push_front(*v2 % *v1); break;
    };

    delete v1;
    delete v2;
  }

}
