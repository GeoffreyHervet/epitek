/*
** OneTime.h for ex02 in /home/hervet_g/piscine/piscine_cpp_d17-2015-hervet_g/ex02
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Jan 20 10:50:13 2012 geoffrey hervet
** Last update Fri Jan 20 10:50:13 2012 geoffrey hervet
*/

#ifndef   __ONETIME_H__
# define  __ONETIME_H__

# include	<string>

# include	"IEncryptionMethod.h"

class		OneTime:
  public	  IEncryptionMethod
{
  std::string	_key;
  int		_idxDe;
  int		_idxCr;

  public:
    OneTime(std::string const &k) : _key(k), _idxDe(0), _idxCr(0){
      size_t	idx = 0;
      while (idx < this->_key.size())
      {
        if (this->_key[idx] >= 'A' && this->_key[idx] <= 'Z')
          this->_key[idx] += 'a' - 'A';
        idx++;
      }
    };
    virtual ~OneTime(){};

    virtual void reset() { this->_idxDe = 0;this->_idxCr = 0; };
    virtual void  encryptChar(char c);
    virtual void  decryptChar(char c);
};

#endif     /* !__ONETIME_H__ */
