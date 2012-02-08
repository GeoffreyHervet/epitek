#ifndef OBJET_HH_
# define OBJET_HH_

typedef enum
{
  OBJET,
  EMBALLAGE,
  CARTON,
  PAPIER_CADEAU,
  JOUET,
  NOUNOURS,
  PETIT_PONEY
} type;

class Objet
{
  public:
    Objet();
    Objet(Objet const&);
    Objet const& operator=(Objet const&);
    ~Objet();

  protected:
    type type_;

  public:
    type getType() const;
    bool isJouet();
    bool isEmballage();
    virtual bool isJouet() const = 0;
};

Objet** MesTestUnitaires();
Objet* MesTestUnitaires(Objet**);

#endif /* !OBJET_HH_ */
