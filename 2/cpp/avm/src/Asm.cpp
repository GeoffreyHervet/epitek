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
  /* Empile la valeur au sommet de la pile */
  void            Stack::push(IOperand *val)
  {
    this->_val.push_front(val);
  }

  /* Depile la valeur au sommet de la pile */
  void            Stack::pop()
  {
    if (this->_val.empty())
      throw Stack::Error("Double without dec");
    delete this->_val.front();
    this->_val.pop_front();
  }

  /* Affiche chaque valeur sur la pile de la plus recente a la plus ancienne.
     Deque permet d'effectuer des operations sur les deux extremites de la liste */
  void            Stack::dump()
  {
    std::deque<IOperand *>::iterator      iter;

    for (iter = this->_val.begin() ; iter != this->_val.end() ; ++iter)
      std::cout << (*iter)->toString() << std::endl;
  }

  /* Sommet de la pile egale a celle passee en parametre? */
  void            Stack::assert(IOperand *val)
  {
    if (this->_val.size() < 1)
      {
	delete val;
	throw Stack::Error("Empty Stack!");
      }
    if (val->getPrecision() == this->_val.front()->getPrecision() &&
	val->toString() == this->_val.front()->toString())
      return ;
    {
      delete val;
      throw Stack::Error("Assert Fail");
    }
  }

  void            Stack::add()
  {
    IOperand      *res;

       if (this->_val.size() < 2)
      throw Stack::Error("You try to add without two arg in stack");

    IOperand      *v1 = this->_val.front();
    this->_val.pop_front();

    IOperand      *v2 = this->_val.front();
    this->_val.pop_front();

    res = *v1 + *v2;

    this->_val.push_front(res);
    delete v1;
    delete v2;

  }

  void            Stack::sub()
  {
    IOperand      *res;

    if (this->_val.size() < 2)
      throw Stack::Error("You try to add without two arg in stack");

    IOperand      *v1 = this->_val.front();
    this->_val.pop_front();

    IOperand      *v2 = this->_val.front();
    this->_val.pop_front();

    res = *v2 - *v1;

    this->_val.push_front(res);
    delete v1;
    delete v2;
  }

  void            Stack::mul()
  {
    IOperand      *res;

    if (this->_val.size() < 2)
      throw Stack::Error("You try to mul without two arg in stack");

    IOperand      *v1 = this->_val.front();
    this->_val.pop_front();

    IOperand      *v2 = this->_val.front();
    this->_val.pop_front();

    res = (*v2) * (*v1);

    this->_val.push_front(res);
    delete v1;
    delete v2;
  }

  void		Stack::div()
  {
    IOperand      *res;

    if (this->_val.size() < 2)
      throw Stack::Error("You try to div without two arg in stack");

    IOperand      *v1 = this->_val.front();
    this->_val.pop_front();

    IOperand      *v2 = this->_val.front();
    this->_val.pop_front();

    res = *v2 / *v1;

    this->_val.push_front(res);
    delete v1;
    delete v2;
  }

  void            Stack::mod()
  {
    IOperand      *res;

    if (this->_val.size() < 2)
      throw Stack::Error("You try to div without two arg in stack");

    IOperand      *v1 = this->_val.front();
    this->_val.pop_front();

    IOperand      *v2 = this->_val.front();
    this->_val.pop_front();

    res = *v2 % *v1;

    this->_val.push_front(res);
    delete v1;
    delete v2;
  }


  /* Valeur au sommet de la pile est un entier de 8 bits?
     L'interprete comme une valeur ascii et affiche le char
     sur la sortie standard */
  void            Stack::print()
  {
    std::stringstream     ss;
    short                 tmp;
    char                  c;

    if (this->_val.size() < 1)
      throw Stack::Error("Empty stack! Can't print!");
    if (this->_val.front()->getType() == INT8)
      {
	ss.str(this->_val.front()->toString());
	ss >> tmp;
	c = tmp;
	std::cout << c << std::endl;
      }
    else
      throw Stack::Error("Top of stack is not Int8");
  }
}
