#ifndef				__LEXER_H__
# define			__LEXER_H__

# include			<iostream>
# include			<iomanip>
# include			<string>
# include			<queue>
# include			<map>

# include			"macros.h"

namespace			avm
{
  class				Lexer
  {
    public:
      class			Token
      {
        public:
          enum			eType
          {
            NONE,
            INSTR,
            VALUE,
            INT,
            FLOAT
          };

        protected:
          Token::eType		_type;
          std::string		_value;

        public:
          Token(Lexer::Token::eType, const std::string &);
          Token() {};
          ~Token();
          Token(const Lexer::Token &);
          Lexer::Token		&operator=(const Lexer::Token &);

          const std::string		&getValue() const { return this->_value; };
          const Lexer::Token::eType	&getType() const { return this->_type; };

          void				setValue(const std::string &);
          void				setType(const Lexer::Token::eType);
      };

      class			Error :
        public			  std::exception
      {
        std::string		_what;

        public:
          Error(const std::string &e) throw() : std::exception(), _what(e) {};
          ~Error() throw() {};
          Error(const Lexer::Error &e) throw() : std::exception(), _what(e.what()) {};
          Error		&operator=(const Error &e) throw();

          const char		*what(void) const throw() { return this->_what.c_str(); };
      };

    protected:
      bool			_resetQueue;
      bool			_eof;
      bool			_exit;
      std::string		_fileName;
      std::istream		&_input;
      std::ifstream		*_file;
      std::queue<Lexer::Token>	_tokens;
      std::map<std::string, Token::eType> _map;

      Lexer(const Lexer &);
      Lexer			&operator=(const Lexer &);

    public:
      Lexer();
      ~Lexer();

      std::queue<Lexer::Token>	lex(void);

      bool			getExit() const { return this->_exit; };
      void			setFileName(const char *);

      bool			eof(void) const { return this->_eof; };

    protected:
      void		        resetQueue(void);
      std::string		getLine(void);
      void			initMap();
      bool			isInt(const std::string &);
      bool			isFloat(const std::string &);
      Token::eType		getType(const std::string &);
      bool			isComment(const std::string &);
      void			check_parenthesis(std::string &);
  };

};

std::ostream			&operator<<(std::ostream &os, const avm::Lexer::Token &t);
#if 0
S := [INSTR SEP]*

INSTR :=	  ; avm::Lexer::eType::INSTR
  push VALEUR
| pop
| dump
| assert VALEUR
| add
| sub
| mul
| div
| mod
| print
| exit

VALEUR :=	; avm::Lexer::eType::VALUE
  int8(N)
| int16(N)
| int32(N)
| float(Z)
| double(Z)

N := [-]?[0..9]+ ; avm::Lexer::eType::INT

Z := [-]?[0..9]+.[0..9]+ ; avm::Lexer::eType::FLOAT

SEP := '\n'

#endif

#endif     /* !__LEXER_H__ */
