/*
** BF_Translator.h for piscine_cpp_d16-2015-hervet_g in /home/hervet_g/piscine/piscine_cpp_d16-2015-hervet_g
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Thu Jan 19 18:13:38 2012 geoffrey hervet
** Last update Thu Jan 19 18:13:38 2012 geoffrey hervet
*/

#ifndef   __BF_TRANSLATOR_H__
# define  __BF_TRANSLATOR_H__

# include	<string>
# include	<map>

class		BF_Translator
{
  std::map<char, std::string> _map;

  public:
    BF_Translator();

    int		translate(std::string, std::string);
};


#endif     /* !__BF_TRANSLATOR_H__ */
