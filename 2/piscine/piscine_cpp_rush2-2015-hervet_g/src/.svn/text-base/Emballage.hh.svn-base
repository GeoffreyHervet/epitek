#ifndef EMBALLAGE_HH_
# define EMBALLAGE_HH_

# include "Objet.hh"

class Emballage : public Objet
{
  public:
    Emballage();
    Emballage(Emballage const&);
    Emballage const& operator=(Emballage const&);
    ~Emballage();

  private:
    Objet* objet_;

  public:
    void setObjet(Objet* src);
    Objet* getObjet() const;

  public:
    virtual bool emballeMoiCa(Objet*, bool verbose=true);
    virtual Objet* ouvreMoi();
    virtual bool isJouet() const { return false; };
};

#endif /* !EMBALLAGE_HH_ */
