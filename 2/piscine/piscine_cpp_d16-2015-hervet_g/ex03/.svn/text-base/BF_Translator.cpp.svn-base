//
// BF_Translator.cpp for piscine_cpp_d16-2015-hervet_g in /home/hervet_g/piscine/piscine_cpp_d16-2015-hervet_g
//
// Made by geoffrey hervet
// Login   <hervet_g@epitech.net>
//
// Started on  Thu Jan 19 18:13:45 2012 geoffrey hervet
// Last update Thu Jan 19 18:13:45 2012 geoffrey hervet
//

#include	<string>
#include	<iomanip>
#include	<fstream>
#include	<iostream>
#include	<vector>

#include	"BF_Translator.h"

static bool	is_good_char(const char c)
{
  return c == '+' || c == '-' || c == '>' || c == '<' || c == '.' || c == ',' ||  c == '[' || c == ']';
}

BF_Translator::BF_Translator()
{
  this->_map['+'] = "(*p)++;";
  this->_map['-'] = "(*p)--;";
  this->_map['>'] = "p++;";
  this->_map['<'] = "p--;";
  this->_map['.'] = "write(1, p, 1);";
  this->_map[','] = "read(0, p, 1);";
  this->_map['['] = "while (*p) {";
  this->_map[']'] = "}";
}

int		BF_Translator::translate(std::string in, std::string out)
{
  std::ifstream	input;
  std::ofstream	output;

  input.open(in.c_str(), std::ifstream::out);
  if (!input.is_open())
    return -1;
  output.open(out.c_str(), std::ofstream::out | std::ofstream::trunc);
  if (!output.is_open())
    return -1;
  output << "#include <unistd.h>\n#include <stdlib.h>\nint main(){\n char *p; if ((NULL == (p = malloc(60 * 1024)))) return 1;\n";
  while (!input.eof())
  {
    char    c;
    input.get(c);
    if (!c)
      break;
    if (is_good_char(c))
      output << "\t" << this->_map[c] << "\n";
  }
  output << "return 0;}" << std::flush;
  output.close();
  input.close();
  return 0;
}
