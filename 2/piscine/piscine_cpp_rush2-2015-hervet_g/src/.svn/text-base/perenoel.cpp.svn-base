#include	<string>
#include	<iostream>
#include	<fstream>
#include	<iomanip>

#include	"Trace.hh"

#include "ElfDePePeNoel.hh"
#include "PetitPoney.hh"
#include "TablePePeNoel.hh"
#include "TapisRoulantPePeNoel.hh"
#include "Carton.hh"
#include "PapierCadeau.hh"
#include "Nounours.hh"
#include "Objet.hh"

static size_t limitArgs = 2;
static std::string labels[] = { "Nounours", "PetitPoney", "PapierCadeau", "Carton", ""};
static Objet* (*ptrs[])(const std::string &name) = {
  (Objet* (*)(const std::string &name)) & Nounours::createInstance,
  (Objet* (*)(const std::string &name)) & PetitPoney::createInstance,
  (Objet* (*)(const std::string &name)) & PapierCadeau::createInstance,
  (Objet* (*)(const std::string &name)) & Carton::createInstance
};

Objet*	getStrForInstance(size_t idx, std::ifstream &file)
{
  TRACE_EXEC();
  std::string	str;
  std::string	word = "";

  while (!file.eof())
  {
    file >> str;
    if (str == ("</" + labels[idx] + ">"))
      return (ptrs[idx])(word);
    word = str;
  }
  return NULL;
}

Objet*	getInstanceOfType(std::string &type, std::ifstream &file)
{
  TRACE_EXEC();
  size_t idx = 0;
  Objet	*ret;

  for (idx = 0; labels[idx] != ""; idx++)
  {
    if (labels[idx] == type)
    {
      if (idx < limitArgs)
        ret = getStrForInstance(idx, file);
      else
        ret = (ptrs[idx])("");
      if (ret == NULL)
        std::cerr << "An error occured !" << std::endl;
      return ret;
    }
  }
  return NULL;
}

void	freeObjRec(Objet *content, Objet *obj)
{
  TRACE_EXEC();

  if (content != obj && content!= NULL)
    freeObjRec(((Emballage *)content)->getObjet(), obj);
  delete content;
}

void	parseFile(std::ifstream &file)
{
  TRACE_EXEC();
  std::string line;
  Objet	*obj;
  Objet	*prev = NULL;
  Objet	*content = NULL;

  (void)obj;
  do
  {
    file >> line;
    if (line[0] == '<' && line[1] != '/')
    {
      line = line.substr(1, line.size() - 2);
#ifdef TRACE
      std::cout << "Lecture du XML : \"" << line << "\"" << std::endl;
#endif
      if (NULL == (obj = getInstanceOfType(line, file)))
        break;
      if (content == NULL)
        content = obj;
      if (obj->isJouet() == true)
      {
        std::cout << "Cher inspecteur des travaux finis, je t'annonce que j'ai debale " << ((Jouet *)obj)->getLabel() << " et que je le fait crier : " << std::endl;
        ((Jouet *)obj)->estPris();
        freeObjRec(content, obj);
        delete obj;
        return;
      }
      else
        ((Emballage *)obj)->ouvreMoi();
      if (prev != NULL)
        ((Emballage *)prev)->emballeMoiCa(obj, false);
      prev = obj;
    }
    else
      std::cout << " --- " << line << std::endl;
  } while (!file.eof());
}

void	initFile(char *fileName)
{
  TRACE_EXEC();
  std::ifstream file;

  file.open(fileName, std::ifstream::out);
  if (false == file.is_open())
    std::cerr << "perenoel: " << fileName << ": Can't read file \"" << fileName << "\"" << std::endl;
  else
    parseFile(file);
}

int main(int ac, char **av)
{
  TRACE_EXEC();
  if (ac < 2)
  {
    std::cerr << "perenoel: Usage : " << av[0] << " file [...]" << std::endl;
    return 1;
  }
  int idx = 1;
  while (idx < ac)
    initFile(av[idx++]);
  return 0;
}
