#ifndef TAPISROULANTPEPENOEL
# define TAPISROULANTPEPENOEL

# include <string>

# include "ITapisRoulant.hh"
# include "Objet.hh"

class TapisRoulantPePeNoel : public ITapisRoulant
{
  public:
    TapisRoulantPePeNoel();
    TapisRoulantPePeNoel(TapisRoulantPePeNoel const&);
    TapisRoulantPePeNoel const& operator=(TapisRoulantPePeNoel const&);
    ~TapisRoulantPePeNoel();

  public:
    bool poser(Objet*);
    Objet* prendre();
    Objet* Regarder() const;
    Emballage* IN();
    bool OUT();
};

#endif /* !TAPISROULANTPEPENOEL */
