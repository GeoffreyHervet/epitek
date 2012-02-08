#include	<iostream>
#include	<queue>

#include	"Lexer.h"
#include	"Stack.hh"

int		main(const int ac, const char **av)
{
  unsigned int	line = 1;
  avm::Lexer	lex;
  avm::Stack	content;

  try
  {
    std::queue<avm::Lexer::Token>	lexem;
    if (ac == 2)
      lex.setFileName(av[1]);
    else if (ac > 2)
    {
      std::cout << "avm : Usage " << av[0] << " [file]" << std::endl;
      return 1;
    }
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
        throw avm::Lexer::Error("WTF ? Where is exit?");
    }
    catch (std::exception &e)
    {
      std::cerr << "Parse error at line " << line << " : "  << e.what() << std::endl;
    }
  }
  catch (std::exception &e)
  {
      std::cerr << "An error occured : " << e.what() << std::endl;
  }
  return 0;
}
