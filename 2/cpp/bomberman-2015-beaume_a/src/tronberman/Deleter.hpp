#ifndef DELETER_HPP_
# define DELETER_HPP_

struct deleter
{
  public:
    template <class tmp>
    void operator()(tmp *val)
    {
      delete val;
    };
};

#endif /* DELETER_HPP_ */
