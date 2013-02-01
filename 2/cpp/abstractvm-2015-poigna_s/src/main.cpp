#include	<iostream>
#include	<queue>
#include	<stdexcept>

#include	"Lexer.h"
#include	"Stack.hh"

static int	launcher(avm::Lexer &lex)
{
  unsigned int	line = 1;
  avm::Stack	content;
  std::queue<avm::Lexer::Token>	lexem;

  try
  {
    while (!lex.eof())
    {
      lexem = lex.lex();
      if (!lexem.empty())
        content.func_call(lexem);
      while (!lexem.empty())
      {
        std::cout << lexem.front() << std::endl;
        lexem.pop();
      }
      ++line;
    }
    if (!lex.getExit())
    {
      if (content.haveToThrowExit())
        throw avm::Lexer::Error("WTF ? Where is exit?");
      return 1;
    }
  }
  catch (std::overflow_error &e)
  {
    std::cerr << "An overflow has been detected on instruction line " << line << "! " << e.what() << std::endl;
    return 1;
  }
  catch (std::exception &e)
  {
    std::cerr << "Error on line " << line << " : "  << e.what() << std::endl;
    return 1;
  }
  return 0;

}

int		main(const int ac, const char **av)
{
  avm::Lexer	lex;

  try
  {
    if (ac == 2)
      lex.setFileName(av[1]);
    else if (ac > 2)
    {
      std::cout << "avm : Usage " << av[0] << " [file]" << std::endl;
      return 1;
    }
    if (launcher(lex))
      return 1;
  }
  catch (std::exception &e)
  {
    std::cerr << "An error occured : " << e.what() << std::endl;
  }
  return 0;
}
