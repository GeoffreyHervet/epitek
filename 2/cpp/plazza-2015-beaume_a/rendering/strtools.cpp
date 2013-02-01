//
// strtools.cpp for  in /home/tortor_t//Documents/prog/plazza/src
// 
// Made by thomas tortorini-kanan
// Login   <tortor_t@epitech.net>
// 
// Started on  Fri Apr 13 11:49:40 2012 thomas tortorini-kanan
// Last update Fri Apr 13 19:28:35 2012 thomas tortorini-kanan
//

#include			<string>

std::string&			strToLower(std::string& s)
{
  for (int i = s.size() - 1; i >= 0; --i)
    s[i] = tolower(s[i]);
  return s;
}

void				strReplaceChar(std::string& str, char a, char b)
{
  unsigned			i;

  for (i = 0; str[i]; ++i)
    if (str[i] == a)
      str[i] = b;
}
