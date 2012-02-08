#ifndef TABLEALEAT_HH_
# define TABLEALEAT_HH_

# include "ITable.hh"

class TableAleat : public ITable
{
  public:
    TableAleat(unsigned int maxObj = 10);
    TableAleat(TableAleat const&);
    TableAleat const& operator=(TableAleat const&);
    ~TableAleat();

  private:
    Objet** objets_;
    unsigned int nbrObjets_;

  public:
    bool poser(Objet*);
    Objet* prendre();
    Objet* prendre(int i);
    Objet* prendre(Objet*);
    Objet** Regarder();
    void fillRandom();
};

#endif /* !TABLEALEAT_HH_ */
