//
// Parser.cpp for ex00 in /home/hervet_g/piscine/piscine_cpp_d16-2015-hervet_g/ex00
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Thu Jan 19 09:30:46 2012 geoffrey hervet
// Last update Thu Jan 19 09:30:46 2012 geoffrey hervet
//

#include	<iostream>
#include	<stdlib.h>

#include	"Parser.h"

Parser::operators	Parser::getOperand(const char c) const
{
  if (c == '/') return Parser::DIV; //1
  if (c == '%') return Parser::MOD; //2
  if (c == '*') return Parser::MULT;//3
  if (c == '-') return Parser::MINUS;//4
  if (c == '+') return Parser::PLUS;//5
  if (c == '(') return Parser::PAR_L;
  if (c == ')') return Parser::PAR_R;
  return Parser::NO;
};

void		Parser::reset()
{
  this->_result = 0;
}

int		Parser::result() const
{
  return this->_result;
}

static int	getInt(const std::string str, size_t &idx)
{
  size_t	end;
  int		ret;

  for (end = idx; isdigit(str[end]) && end < str.size(); end++);
  ret = atoi(str.c_str() + idx);
  idx = end - 1; // pour l'incre dans setOperation
  return ret;
}

static void	setOperation(std::stack<int> &nbrs, std::stack<Parser::operators> &oper)
{
  int		n[2] = {0, 0};
  Parser::operators o = oper.top();

  if (oper.top() == Parser::PAR_R)
    oper.pop();
  do
  {
    o = oper.top();
    oper.pop();
    n[0] = nbrs.top();
    nbrs.pop();
    n[1] = nbrs.top();
    nbrs.pop();

    switch (o)
    {
      case Parser::DIV:
        nbrs.push(n[1] / n[0]);
      break;
      case Parser::MOD:
        nbrs.push(n[1] % n[0]);
      break;
      case Parser::MULT:
        nbrs.push(n[1] * n[0]);
      break;
      case Parser::MINUS:
        nbrs.push(n[1] - n[0]);
      break;
      case Parser::PLUS:
        nbrs.push(n[1] + n[0]);
      break;
      default:
      break;
    }
  } while (!oper.empty() && oper.top() != Parser::PAR_L);
  oper.pop();
}

void		Parser::feed(const std::string &str)
{
  size_t		idx = 0;
  std::stack		<int>operandes;
  std::stack		<Parser::operators>operators;
  Parser::operators	tmp_op;

  while (idx < str.size())
  {
    if (str[idx] != ' ')
    {
      tmp_op = this->getOperand(str[idx]);
      if (tmp_op != NO)
        operators.push(tmp_op);
      else
        operandes.push(getInt(str, idx));
      if (!operators.empty() && operators.top() == Parser::PAR_R)
        setOperation(operandes, operators);
    }
    idx++;
  }
  if (operators.size())
    setOperation(operandes, operators);
  this->_result += operandes.top();
}
