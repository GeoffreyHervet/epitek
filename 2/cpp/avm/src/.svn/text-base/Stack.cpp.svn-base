#include	<iterator>
#include	<string>
#include	<iterator>
#include	<sstream>
#include	<sys/types.h>
#include	<deque>
#include	<map>
#include	<iostream>

#include	"IOperand.hh"
#include	"Operands.hh"
#include	"Stack.hh"

namespace	avm
{
  Stack::Stack()
  {
    this->function["pop"]	= &Stack::pop;
    this->function["dump"]	= &Stack::dump;
    this->function["add"]	= &Stack::add;
    this->function["sub"]	= &Stack::sub;
    this->function["mul"]	= &Stack::mul;
    this->function["div"]	= &Stack::div;
    this->function["mod"]	= &Stack::mod;
    this->function["print"]	= &Stack::print;

    this->type_of_func["int8"]	= &Stack::createInt8;
    this->type_of_func["int16"]	= &Stack::createInt16;
    this->type_of_func["int32"]	= &Stack::createInt32;
    this->type_of_func["float"]	= &Stack::createFloat;
    this->type_of_func["double"]= &Stack::createDouble;
  }

  Stack::~Stack()
  {
    while (!this->_val.empty())
    {
      delete this->_val.front();
      this->_val.pop_front();
    }
  }

  IOperand                *Stack::get_Op(std::queue<avm::Lexer::Token> &lexem)
  {
    if (lexem.empty())
      throw Stack::Error("Error : instruction need a value");

    Lexer::Token	type = lexem.front();
    lexem.pop();

    if (type.getType() != Lexer::Token::VALUE)
      throw Stack::Error("Error : instruction need a value");
    if (lexem.empty())
      throw Stack::Error("Error : value need a number !");

    Lexer::Token	value = lexem.front();
    lexem.pop();
    if (value.getType() != Lexer::Token::INT && value.getType() != Lexer::Token::FLOAT)
      throw Stack::Error("Error : value need a number !");

    return (this->*type_of_func[type.getValue()])(value.getValue());
  }


  /*
   * changer, prendre une queue de Lexer::Token (pour sarah : la queue)
   */

  void            Stack::func_call(std::queue<avm::Lexer::Token> &lexem)
  {
    std::string   type;
    Lexer::Token	tok;

    tok = lexem.front();
    lexem.pop();

    if (tok.getType() != Lexer::Token::INSTR)
    {
      std::cout << "throw c'est pas une instruction !" << std::endl;
      return ;
    }
    if (tok.getValue() != "exit")
    {
      if (tok.getValue() == "push")
	this->push(this->get_Op(lexem));
      else if (tok.getValue() == "assert")
	this->assert(this->get_Op(lexem));
      else
      {
        if (lexem.size())
          std::cerr << "Warning ! Instruction " << tok.getValue() << " doesn't required value" << std::endl;
        (this->*function[tok.getValue()])();
      }
    }
  }

  IOperand        *Stack::createInt8(std::string const& value)
  {
    return (new Operand<int8_t>(value, INT8));
  }

  IOperand        *Stack::createInt16(std::string const& value)
  {
    return (new Operand<int16_t>(value, INT16));
  }

  IOperand        *Stack::createInt32(std::string const& value)
  {
    return (new Operand<int32_t>(value, INT32));
  }

  IOperand        *Stack::createFloat(std::string const& value)
  {
    return (new Operand<float>(value, FLOAT));
  }

  IOperand        *Stack::createDouble(std::string const& value)
  {
    if (value.find('.') == value.npos)
      throw Stack::Error("Double without dec");
    return (new Operand<double>(value, DOUBLE));
  }

  Stack::Error			&Stack::Error::operator=(const Stack::Error &e) throw()
  {
    if (this != &e)
      this->_what = e.what();
    return *this;
  }

};
