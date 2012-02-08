#include <iostream>
#include <string>

#include "Trace.hh"

#include "Jouet.hh"

Jouet::Jouet(std::string const& label) : Objet(), label_(label)
{
  TRACE_EXEC();
  std::cout << "label : " << label << std::endl;
  this->type_ = JOUET;
}

Jouet::Jouet(Jouet const& src) : Objet(), label_(src.label_)
{
  TRACE_EXEC();
  this->type_ = JOUET;
}

Jouet const& Jouet::operator=(Jouet const& src)
{
  TRACE_EXEC();
  if (this != &src)
  {
    this->label_ = src.label_;
  }
  return (src);
}

Jouet::~Jouet()
{
  TRACE_EXEC();
}

std::string Jouet::getLabel() const
{
  TRACE_EXEC();
  return (this->label_);
}
