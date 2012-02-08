#ifndef PAPIERCADEAU_HH_
# define PAPIERCADEAU_HH_

# include <string>
# include "Emballage.hh"

class PapierCadeau : public Emballage
{
  public:
    PapierCadeau();
    PapierCadeau(PapierCadeau const&);
    PapierCadeau const& operator=(PapierCadeau const&);
    ~PapierCadeau();
    static PapierCadeau *createInstance(const std::string &name){(void)name;return new PapierCadeau();};
};

#endif /* !PAPIERCADEAU_HH_ */
