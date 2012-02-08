/*
** Cesar.h for ex02 in /home/hervet_g/piscine/piscine_cpp_d17-2015-hervet_g/ex02
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Jan 20 10:49:58 2012 geoffrey hervet
** Last update Fri Jan 20 10:49:58 2012 geoffrey hervet
*/

#ifndef   __CESAR_H__
# define  __CESAR_H__

# include "IEncryptionMethod.h"

class		Cesar:
  public	  IEncryptionMethod
{
  int		_decDe;
  int		_decCr;

  public:
    Cesar(){this->reset();};
    virtual ~Cesar(){};

    virtual void  encryptChar(char c);
    virtual void  decryptChar(char c);
    virtual void  reset() { this->_decDe = 3; this->_decCr = 3;};
};

#endif     /* !__CESAR_H__ */
