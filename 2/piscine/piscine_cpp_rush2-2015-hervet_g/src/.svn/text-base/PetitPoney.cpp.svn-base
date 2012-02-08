#include <iostream>
#include <string>

#include "Trace.hh"

#include "PetitPoney.hh"

PetitPoney::PetitPoney(std::string const& label) : Jouet(label)
{
  TRACE_EXEC();
  this->type_ = PETIT_PONEY;
}

PetitPoney::PetitPoney(PetitPoney const& src) : Jouet(src.label_)
{
  TRACE_EXEC();
  this->type_ = PETIT_PONEY;
}

PetitPoney const& PetitPoney::operator=(PetitPoney const& src)
{
  TRACE_EXEC();
  if (this != &src)
  {
    this->label_ = src.label_;
  }
  return (src);
}

PetitPoney::~PetitPoney()
{
  TRACE_EXEC();
}

void PetitPoney::estPris() const
{
  TRACE_EXEC();
  std::cout << "yo man" << std::endl;
}
