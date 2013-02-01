#ifndef		TUPLE_HH_
# define	TUPLE_HH_

template <typename T, typename V>
class		Tuple
{
  const T	_item1;
  const V	_item2;

  public:
   Tuple(const T &item1, const V &item2) : _item1(item1), _item2(item2) {};
   ~Tuple(){};
   
   Tuple<T,V>	operator=(const Tuple<T,V> &) { return *this; };
   Tuple(const Tuple<T,V> &t) : _item1(t.getLeft()), _item2(t.getRight()) {};

   T		getLeft(void) const { return this->_item1; };
   V		getRight(void) const { return this->_item2; };
};

#endif /* SRC/TUPLE_HH_ */
