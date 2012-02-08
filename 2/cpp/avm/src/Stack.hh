#ifndef			_STACK_HH_
#define			_STACK_HH_

#include		<iostream>
#include		<deque>
#include		<string>
#include		<map>
#include		<queue>

#include		"IOperand.hh"
#include		"Lexer.h"

namespace		avm
{

  class			Stack
  {
    public:
      class		Error :
        public		  std::exception
    {
      std::string	_what;

      public:
      Error(const std::string &e) throw() : _what(e) {};
      ~Error() throw() {};
      Error(const Stack::Error &e) throw() : _what(e.what()) {};
      Error		&operator=(const Error &e) throw();

      const char		*what(void) const throw() { return this->_what.c_str(); };
    };


  private:
    std::deque<IOperand*> _val;
    std::map<std::string, void (Stack::*)()> function;
    std::map<std::string, IOperand* (Stack::*)(std::string const&)> type_of_func;

  public:
    Stack();
    ~Stack();

    void            	func_call(std::queue<avm::Lexer::Token> &lexem);

  private:

    IOperand		*get_Op(std::queue<avm::Lexer::Token> &lexem);
    IOperand * createInt8(std::string const& value);
    IOperand * createInt16(std::string const& value);
    IOperand * createInt32(std::string const& value);
    IOperand * createFloat(std::string const& value);
    IOperand * createDouble(std::string const& value);
    void	push(IOperand *arg);
    void  pop();
    void  dump();
    void  assert(IOperand *arg);
    void  add();
    void  sub();
    void  mul();
    void  div();
    void  mod();
    void  print();
  };
};

#endif		/* _STACK_HH_ */
