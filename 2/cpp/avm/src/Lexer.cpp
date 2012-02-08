#include	<algorithm>
#include	<iostream>
#include	<fstream>
#include	<sstream>

#include	"Lexer.h"
#include	"utils.h"


namespace avm
{
  /*
  ** ******************************************
  ** *                Lexer                   *
  ** ******************************************
  */

  Lexer::Lexer()
    : _resetQueue(false),
      _eof(false),
      _exit(0),
      _fileName(""),
      _input(std::cin),
      _file(NULL)
  {
    this->initMap();
  }

  Lexer::~Lexer()
  {
    this->resetQueue();
    if (this->_file != NULL)
    {
      this->_file->close();
      delete this->_file;
    }
  }

  /*
  ** Parse la ligne
  */
  std::queue<Lexer::Token>	Lexer::lex(void)
  {
    Token			tok;
    std::string			word(this->getLine());
    int				idx = 0;

    this->resetQueue();

    if ((word.empty()) || (word[0] == ';' && word[1] != ';'))
      return this->_tokens;

    std::stringstream		line(word);

    while (line.good())
    {
      std::getline(line, word, ' ');
      if (word.empty())
        break;
      if (!idx++ && word == ";;")
      {
        this->_eof = true;
        break;
      }
      if (this->isComment(word))
        break;
      tok.setValue(word);
      tok.setType(this->getType(tok.getValue()));
      this->_tokens.push(tok);
    }
    return this->_tokens;
  }

  void				Lexer::setFileName(const char *fileName)
  {
    this->resetQueue();
    this->_fileName = fileName;
    this->_eof = false;
    this->_exit = false;

    this->_file = new std::ifstream(fileName);
    if (!this->_file->is_open())
      throw Lexer::Error("Can't open file!");
  }

  void				Lexer::initMap()
  {
    this->_map["push"] = Lexer::Token::INSTR;
    this->_map["pop"] = Lexer::Token::INSTR;
    this->_map["dump"] = Lexer::Token::INSTR;
    this->_map["assert"] = Lexer::Token::INSTR;
    this->_map["add"] = Lexer::Token::INSTR;
    this->_map["sub"] = Lexer::Token::INSTR;
    this->_map["mul"] = Lexer::Token::INSTR;
    this->_map["div"] = Lexer::Token::INSTR;
    this->_map["mod"] = Lexer::Token::INSTR;
    this->_map["print"] = Lexer::Token::INSTR;
    this->_map["exit"] = Lexer::Token::INSTR;

    this->_map["int8"] = Lexer::Token::VALUE;
    this->_map["int16"] = Lexer::Token::VALUE;
    this->_map["int32"] = Lexer::Token::VALUE;
    this->_map["float"] = Lexer::Token::VALUE;
    this->_map["double"] = Lexer::Token::VALUE;
  }

  bool				Lexer::isInt(const std::string &str)
  {
    unsigned int		idx = 0;

    if (str[idx] == '-')
      ++idx;
    for (; str[idx]; ++idx)
      if (!IS_DIGIT(str[idx]))
        return false;
    return true;
  }

  bool				Lexer::isFloat(const std::string &str)
  {
    unsigned int		idx = 0;
    bool			allery_dot = false;

    if (str[idx] == '-')
      ++idx;
    for (; str[idx]; ++idx)
      if (!IS_DIGIT(str[idx]))
      {
        if (str[idx] == '.' && !allery_dot)
          allery_dot = true;
        else
          return false;
      }
    return true;
  }

  Lexer::Token::eType		Lexer::getType(const std::string &str)
  {
    Lexer::Token::eType		type;

    type = this->_map[str];
    if (str == "exit")
      this->_exit = true;
    if (type != Lexer::Token::NONE)
      return type;
    if (isInt(str))
      return Lexer::Token::INT;
    if (isFloat(str))
      return Lexer::Token::FLOAT;
    std::stringstream		err;
    err << "No type for \"" << str << "\" !";
    throw Lexer::Error(err.str());
    return Lexer::Token::NONE;
  }

  bool				Lexer::isComment(const std::string &str)
  {
    return str[0] == ';' && str[1] != ';';
  }

  /*
  ** get line va soit lire sur std::cin ou sur le fichier passe en parametre
  */
  std::string			Lexer::getLine(void)
  {
    if ((this->_file != NULL && !this->_file->good()) || (this->_file == NULL && !this->_input.good()))
      this->_eof = true;
    if (this->eof())
      return ";;";

    std::string			ret;

    if (this->_file != NULL)
      std::getline(*this->_file, ret);
    else
      std::getline(this->_input, ret);

    if (ret[0] != ';' && !ret.empty())
      this->check_parenthesis(ret);
    return ret;
  }

  void				Lexer::check_parenthesis(std::string &line)
  {
    int				parenthesis = 0;

    for (int idx = 0; line[idx]; idx++)
    {
      if (line[idx] == '(')
        ++parenthesis;
      else if (line[idx] == ')')
        --parenthesis;
      if (parenthesis < 0)
      {
        std::stringstream		err;
        err << "Check parenthesis : \"" << line << "\" !";
        throw Lexer::Error(err.str());
      }
    }
    if (parenthesis)
    {
      std::stringstream		err;
      err << "Check parenthesis : \"" << line << "\" !";
      throw Lexer::Error(err.str());
    }

    std::for_each(line.begin(), line.end(), utils::replace_chars('(', ' '));
    std::for_each(line.begin(), line.end(), utils::replace_chars(')', ' '));
  }

  void		        	Lexer::resetQueue(void)
  {
    while (!this->_tokens.empty())
      this->_tokens.pop();
  }

  /*
  ** ******************************************
  ** *                Error                   *
  ** ******************************************
  */

  Lexer::Error			&Lexer::Error::operator=(const Lexer::Error &e) throw()
  {
    if (this != &e)
      this->_what = e.what();
    return *this;
  }

  /*
  ** ******************************************
  ** *                Tokens                  *
  ** ******************************************
  */

  Lexer::Token::Token(Lexer::Token::eType t, const std::string &s)
    : _type(t),
      _value(s)
  {
  }

  Lexer::Token::~Token()
  {
  }

  Lexer::Token::Token(const Lexer::Token &tok)
    : _type(tok.getType()),
      _value(tok.getValue())
  {
  }

  Lexer::Token			&Lexer::Token::operator=(const Lexer::Token &tok)
  {
    if (this != &tok)
    {
      this->_value = tok.getValue();
      this->_type = tok.getType();
    }
    return *this;
  }

  /* Tokens : setters */

  void			Lexer::Token::setValue(const std::string &str)
  {
    this->_value = utils::strToLower(str);
  }

  void			Lexer::Token::setType(const Lexer::Token::eType type)
  {
    this->_type = type;
  }
};

std::ostream			&operator<<(std::ostream &os, const avm::Lexer::Token &t)
{
  std::cout << "Value \""
    << std::left << t.getValue() << std::flush
    << "\" - Type : " << std::setw(10) << std::left;
  switch (t.getType())
  {
    case avm::Lexer::Token::INSTR: std::cout << "Instruction"; break;
    case avm::Lexer::Token::VALUE: std::cout << "Valeur"; break;
    case avm::Lexer::Token::INT: std::cout << "Integer"; break;
    case avm::Lexer::Token::FLOAT: std::cout << "Float"; break;
    default: std::cout << "Unknow"; break;
  }
  return os;
}

