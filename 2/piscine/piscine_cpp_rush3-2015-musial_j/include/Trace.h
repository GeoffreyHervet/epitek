#ifndef TRACE_H_
# define TRACE_H_

# ifdef TRACE
#  include <iostream>
#  define PRINT_TRACE() \
   do { \
     std::clog << "-> " << __PRETTY_FUNCTION__ << std::endl; \
   } while (0);
# else
#  define PRINT_TRACE()
# endif // !TRACE

#endif // !TRACE_H_
