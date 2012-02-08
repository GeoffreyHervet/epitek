#ifndef STORAGE_H_
# define STORAGE_H_

#include <string>

class Storage
{
 public:
  Storage();
  ~Storage();

 public:
  unsigned int getUsed() const;
  unsigned int getTotal() const;
  unsigned int getPercent() const;
  std::string const& getName() const;

  void setUsed(int);
  void setTotal(int);
  void setName(std::string const&);

 private:
  unsigned int _used;
  unsigned int _total;
  std::string _name;
};


#endif /* !STORAGE_H_ */
