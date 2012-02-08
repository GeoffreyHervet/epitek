#ifndef NOUNOURS_HH_
# define NOUNOURS_HH_

# include <string>

# include "Jouet.hh"

class Nounours : public Jouet
{
  public:
    Nounours(std::string const&);
    Nounours(Nounours const&);
    Nounours const& operator=(Nounours const&);
    virtual ~Nounours();

  public:
    virtual void estPris() const;
    static Nounours *createInstance(const std::string &name){return new Nounours(name);};
};

#endif /* !NOUNOURS_HH_ */
