/*
** Toy.h for ex00 in /home/hervet_g/piscine/piscine_cpp_d13-2015-hervet_g/ex00
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Mon Jan 16 09:26:42 2012 geoffrey hervet
** Last update Mon Jan 16 09:26:42 2012 geoffrey hervet
*/

#include		<iostream>
#include		<string>

#ifndef   __TOY_H__
# define  __TOY_H__

class			Toy
{
  public:
    enum		ToyType
    {
      BASIC_TOY,
      ALIEN,
      BUZZ,
      WOODY
    };

    class		Error
    {
      public:
        enum		ErrorType
        {
          UNKNOWN,
          PICTURE,
          SPEAK
        };
      protected:
        std::string	_what;
        std::string	_where;
      public:
        ErrorType	type;

        void		set(const std::string &a, const std::string &b)
        {
          this->_what = a;
          this->_where = b;
        };

        std::string const &what() const {return this->_what;};
        std::string const &where() const {return this->_where;};
    };

  protected:
    Toy::ToyType	_type;
    std::string		_name;
    std::string		_ascii;
    Toy::Error		_error;

  protected:
    bool		setError(const std::string &wath="", const std::string &where = "", Toy::Error::ErrorType type = Toy::Error::UNKNOWN);

  public:
    Toy();
    Toy(Toy::ToyType type, const std::string &name, const std::string &fileName);
    virtual ~Toy();
    Toy(const Toy&);

    Toy			&operator=(const Toy &);
    Toy			&operator<<(std::string const &_ascii);

    Toy::ToyType	getType() const {return this->_type;};
    const std::string	&getName() const {return this->_name;};
    const std::string	&getAscii() const {return this->_ascii;};

    void		setName(const std::string &name){this->_name = name;};
    bool		setAscii(const std::string &fileName);
    virtual bool	speak(std::string const &sentence){
      std::cout <<  this->getName() << " \"" << sentence << "\"" << std::endl;
      return true;
    };
    virtual bool	speak_es(std::string const &){
      this->setError("wrong mode", __FUNCTION__, Toy::Error::SPEAK); return false;
    };

    const Toy::Error	getLastError() const { return this->_error;};
};

std::ostream		&operator<<(std::ostream &os, const Toy &t);

#endif     /* !__TOY_H__ */
