#ifndef   __UTILS_H__
# define  __UTILS_H__

# include		<string>
# include		<sstream>

namespace		utils
{
  std::string		strToLower(const std::string &);

  template <typename T>
    std::string		toStr(T val) /* prend le param et le renvoie en str */
  {
    std::stringstream	ss;
    ss << val;
    return ss.str();
  };

  struct		replace_chars
  {
    protected:
      char		_a;
      char		_b;

    public:
      replace_chars(char a, char b) : _a(a), _b(b) {};
      void		operator()(char &c) const;
  };
};

#endif     /* !__UTILS_H__ */
