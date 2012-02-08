#ifndef ITAPISROULANT_HH_
# define ITAPISROULANT_HH_

# include <string>

# include "Objet.hh"
# include "Emballage.hh"

class ITapisRoulant
{
  public:
    virtual bool poser(Objet*) = 0;
    virtual Objet* prendre() = 0;
    virtual Objet* Regarder() const = 0;
    virtual Emballage* IN() = 0;
    virtual bool OUT() = 0;

 protected:
    Objet* objet_;
};

ITapisRoulant *creerTapisRoulant();

#endif /* !ITAPISROULANT_HH_ */
