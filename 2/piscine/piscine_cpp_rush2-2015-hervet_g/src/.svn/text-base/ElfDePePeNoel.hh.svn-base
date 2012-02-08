#ifndef ELFDEPEPENOEL_HH_
# define ELFDEPEPENOEL_HH_

# include "IElf.hh"
# include "Objet.hh"
# include "Emballage.hh"
# include "ITable.hh"
# include "ITapisRoulant.hh"

class ElfDePePeNoel : public IElf
{
 public:
  ElfDePePeNoel();
  ElfDePePeNoel(ElfDePePeNoel const&);
  ElfDePePeNoel const& operator=(ElfDePePeNoel const&);
  ~ElfDePePeNoel();

 private:
  Objet* objet_;

 public:
  Emballage* getEmballage();
  void setTable(ITable*);
  void setTapisRoulant(ITapisRoulant*);
  void envoyerObjetAPePeNoel();
  bool emballerCadeau();
  void emballerTousLesCadeaux();

 private:
  bool checkPapierCadeau();
  bool checkJouet();
  bool checkCarton();
  bool findCartonAndPapier();
};

#endif /* !ELFDEPEPENOEL_HH_ */
