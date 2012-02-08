#ifndef TAPISROULANTALEAT
# define TAPISROULANTALEAT

# include <string>

# include "ITapisRoulant.hh"
# include "Objet.hh"

class TapisRoulantAleat : public ITapisRoulant
{
  public:
    TapisRoulantAleat();
    TapisRoulantAleat(TapisRoulantAleat const&);
    TapisRoulantAleat const& operator=(TapisRoulantAleat const&);
    ~TapisRoulantAleat();

  private:
    Objet* objet_;

  public:
    bool poser(Objet*);
    Objet* prendre();
    Objet* Regarder() const;
    Emballage* IN();
    bool OUT();
    bool Zwify();
};

#endif /* !TAPISROULANTALEAT */
