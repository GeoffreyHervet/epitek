
#ifndef ITABLE_HH_
# define ITABLE_HH_

# include <string>

# include "Objet.hh"

class ITable
{
 public:
  virtual bool poser(Objet*) = 0;
  virtual Objet* prendre() = 0;
  virtual Objet* prendre(int i) = 0;
  virtual Objet* prendre(Objet*) = 0;
  virtual Objet** Regarder() = 0;

 public:
  unsigned int maxObj_;
};

ITable *creerTable();

#endif /* ITABLE_HH_ */
