#ifndef PETITPONEY_HH_
# define PETITPONEY_HH_

# include <string>

# include "Jouet.hh"

class PetitPoney : public Jouet
{
  public:
    PetitPoney(std::string const&);
    PetitPoney(PetitPoney const&);
    PetitPoney const& operator=(PetitPoney const&);
    virtual ~PetitPoney();

  public:
    virtual void estPris() const;
    static PetitPoney *createInstance(const std::string &name){return new PetitPoney(name);};
};

#endif /* !PETITPONEY_HH_ */
