#ifndef TRACE_HH_
# define TRACE_HH_

# ifdef TRACE
#  include <iostream>
#  define TRACE_EXEC() \
   do { \
     std::clog << "-> " << __PRETTY_FUNCTION__ << std::endl; \
   } while (0);
# else
#  define TRACE_EXEC()
# endif /* !TRACE */

#endif /* !TRACE_HH_ */
