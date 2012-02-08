#ifndef TABLEPEPENOEL_HH_
# define TABLEPEPENOEL_HH_

# include <string>

# include "ITable.hh"

class TablePePeNoel : public ITable
{
  public:
    TablePePeNoel();
    TablePePeNoel(TablePePeNoel const&);
    TablePePeNoel const& operator=(TablePePeNoel const&);
    ~TablePePeNoel();

  private:
    Objet* objets_[10];
    unsigned int nbrObjets_;

  public:
    bool poser(Objet*);
    Objet* prendre();
    Objet* prendre(int i);
    Objet* prendre(Objet*);
    Objet** Regarder();
    unsigned int maxObj_;
};

#endif /* !TABLEPEPENOEL_HH_ */
