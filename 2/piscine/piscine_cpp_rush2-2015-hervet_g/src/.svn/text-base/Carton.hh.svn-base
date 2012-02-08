#ifndef CARTON_HH_
# define CARTON_HH_

# include "Emballage.hh"

class Carton : public Emballage
{
  public:
    Carton();
    Carton(Carton const&);
    Carton const& operator=(Carton const&);
    ~Carton();

  private:
    bool isOpen_;

  public:
    virtual bool emballeMoiCa(Objet*);
    virtual Objet* ouvreMoi();
    bool fermeMoi();
    static Carton *createInstance(const std::string &name){(void)name; return new Carton();};
};

#endif /* !CARTON_HH_ */
