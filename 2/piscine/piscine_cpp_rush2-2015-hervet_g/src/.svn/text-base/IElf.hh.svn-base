#ifndef IELF_HH_
# define IELF_HH_

# include "ITable.hh"
# include "ITapisRoulant.hh"
# include "Emballage.hh"
# include "PapierCadeau.hh"
# include "Jouet.hh"
# include "Carton.hh"

class IElf
{
  public:
    virtual Emballage* getEmballage() = 0;
    virtual void setTable(ITable*) = 0;
    virtual void setTapisRoulant(ITapisRoulant*) = 0;
    virtual void envoyerObjetAPePeNoel() = 0;
    virtual bool emballerCadeau() = 0;

 protected:
    ITable* table_;
    ITapisRoulant* tapisRoulant_;
    Emballage *emballage_;
    PapierCadeau* papierCadeau_;
    Jouet* jouet_;
    Carton* carton_;
};

#endif /* !IELF_HH_ */
