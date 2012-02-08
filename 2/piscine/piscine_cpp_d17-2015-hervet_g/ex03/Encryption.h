/*
** Encryption.h for ex03 in /home/hervet_g/piscine/piscine_cpp_d17-2015-hervet_g/ex03
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Jan 20 15:01:38 2012 geoffrey hervet
** Last update Fri Jan 20 15:01:38 2012 geoffrey hervet
*/

#ifndef   __ENCRYPTION_H__
# define  __ENCRYPTION_H__

# include	<string>

# include	"IEncryptionMethod.h"

class		Encryption
{
  protected:
    void (IEncryptionMethod::*_handler)(char);
    IEncryptionMethod	*_method;


  public:
    Encryption(IEncryptionMethod &iem, void (IEncryptionMethod::*h)(char));
    ~Encryption(){};

    void	operator()(char c);

    static void encryptString(IEncryptionMethod& encryptionMethod, std::string const& toEncrypt);
    static void decryptString(IEncryptionMethod& encryptionMethod, std::string const& toDecrypt);
};

#endif     /* !__ENCRYPTION_H__ */
