#ifndef JOUET_HH_
# define JOUET_HH_

# include <string>

# include "Objet.hh"

class Jouet : public Objet
{
  public:
    Jouet(std::string const& label);
    Jouet(Jouet const&);
    Jouet const& operator=(Jouet const&);
    virtual ~Jouet();

  protected:
    std::string label_;

  public:
    std::string getLabel() const;
    virtual void estPris() const = 0;
    virtual bool isJouet() const {return true;};
};

#endif /* !JOUET_HH_ */
