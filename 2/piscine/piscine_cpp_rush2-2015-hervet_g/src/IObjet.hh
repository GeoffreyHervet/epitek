#ifndef IOBJET_HH_
# define IOBJET_HH_

enum obj_type__ {NOUNOURS = 1, PETIT_PONEY = 2, EMBALLAGE = 3}

class IObject
{
 protected:
  obj_type__ type_;
};

#endif /* !IOBJET_HH_ */
