#include <sstream>
#include <fstream>
#include <string>

#include "serialize.hh"

void exploreGift(std::ofstream & outfile, Objet * gift)
{
  std::string mapObj[7];
  mapObj[CARTON] = "Carton";
  mapObj[PAPIER_CADEAU] = "PapierCadeau";
  mapObj[NOUNOURS] = "Nounours";
  mapObj[PETIT_PONEY] = "PetitPoney";

  if (gift == NULL)
    return ;
  outfile << "<" << mapObj[gift->getType()] << ">" << std::endl;

  if (gift->getType() == CARTON || gift->getType() == PAPIER_CADEAU)
    exploreGift(outfile, static_cast<Emballage*>(gift)->getObjet());
  else
    outfile << static_cast<Jouet*>(gift)->getLabel() << std::endl;

  outfile << "</" << mapObj[gift->getType()] << ">" << std::endl;
}

bool serializeGift(Objet * gift)
{
  static unsigned int id = 1;
  std::ostringstream converter;

  converter << "cadeau" << id << ".xml";
  std::ofstream outfile (converter.str().c_str(), std::ofstream::binary);

  exploreGift(outfile, gift);

  ++id;
  return (true);
}
