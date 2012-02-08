/*
** DomesticKoala.h for ex01 in /home/hervet_g/piscine/piscine_cpp_d16-2015-hervet_g/ex01
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Thu Jan 19 13:33:34 2012 geoffrey hervet
** Last update Thu Jan 19 13:33:34 2012 geoffrey hervet
*/

#ifndef   __DOMESTICKOALA_H__
# define  __DOMESTICKOALA_H__

# include	<string>
# include	<vector>

# include	"KoalaAction.h"

class		DomesticKoala
{
  public:
    typedef void (KoalaAction::*methodPointer_t)(const std::string &);

  protected:
    std::vector<methodPointer_t> _vect;
    KoalaAction			_koal;

  public:
    DomesticKoala(KoalaAction &);
    ~DomesticKoala(){};
    DomesticKoala(const DomesticKoala &);
    DomesticKoala &operator=(const DomesticKoala &);

    std::vector<methodPointer_t> const * getAction(void) const { return &(this->_vect); };

    void	learnAction(unsigned char, methodPointer_t);
    void	unlearnAction(unsigned char);

    void	doAction(unsigned char, const std::string &);
    void	setKoalaAction(KoalaAction &);

    std::vector<methodPointer_t> getVect() const { return this->_vect; };
    KoalaAction	getKoal() const { return this->_koal; };
};

#endif     /* !__DOMESTICKOALA_H__ */
