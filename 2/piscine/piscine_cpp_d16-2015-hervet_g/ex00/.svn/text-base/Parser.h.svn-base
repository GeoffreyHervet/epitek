/*
** Parser.h for ex00 in /home/hervet_g/piscine/piscine_cpp_d16-2015-hervet_g/ex00
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Thu Jan 19 09:30:43 2012 geoffrey hervet
** Last update Thu Jan 19 09:30:43 2012 geoffrey hervet
*/

#ifndef   __PARSER_H__
# define  __PARSER_H__

#include	<string>
#include	<stack>

class		Parser
{
  int		_result;
  public:
    enum	  	operators
    {
      NO, DIV, MOD, MULT, MINUS, PLUS, PAR_L, PAR_R
    };

  protected:
    Parser::operators	getOperand(const char c) const;

  public:
    Parser() : _result(0){};
    ~Parser(){};
    Parser(const Parser &p){this->_result = p.result();};
    Parser	&operator=(const Parser &p){ if (this != &p){this->_result = p.result();} return *this;};

    void	feed(const std::string &);

    int		result() const;
    void	reset();
};

#endif     /* !__PARSER_H__ */
