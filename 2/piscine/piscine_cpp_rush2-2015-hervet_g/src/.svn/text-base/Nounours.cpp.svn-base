#include <iostream>
#include <string>

#include "Trace.hh"

#include "Nounours.hh"

Nounours::Nounours(std::string const& label) : Jouet(label)
{
  TRACE_EXEC();
  this->type_ = NOUNOURS;
}

Nounours::Nounours(Nounours const& src) : Jouet(src.label_)
{
  TRACE_EXEC();
  this->type_ = NOUNOURS;
}

Nounours const& Nounours::operator=(Nounours const& src)
{
  TRACE_EXEC();
  if (this != &src)
  {
    this->label_ = src.label_;
  }
  return (src);
}

Nounours::~Nounours()
{
  TRACE_EXEC();
}

void Nounours::estPris() const
{
  TRACE_EXEC();
  std::cout << "gra hu" << std::endl;
}
