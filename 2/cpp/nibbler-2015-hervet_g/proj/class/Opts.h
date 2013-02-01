#ifndef OPTS_H_
# define OPTS_H_

# include <string>
# include <map>

class		Opts
{
  std::map<std::string, std::string>	_opts;

  public:
    Opts(int ac, char **av, const char *def = "_default_");
    ~Opts();

    Opts(const Opts &);
    Opts	&operator =(const Opts &);

    const std::string			&operator [](const std::string&);
    const std::string			&getValue(const std::string&);
    void				 setValue(const std::string&, const std::string &);
    bool				 haveOption(const std::string&);
    std::map<std::string, std::string>::const_iterator begin(void) const;
    std::map<std::string, std::string>::const_iterator end(void) const;
};

#endif /* CLASS/OPTS_H_ */
