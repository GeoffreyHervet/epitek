/*
** my_errno_aff.c for my in /home/hervet_g//work/projets/minishel/lib/my
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed Dec 22 11:22:49 2010 geoffrey hervet
** Last update Wed Dec 22 12:08:10 2010 geoffrey hervet
*/

#include		<stdlib.h>
#include		<errno.h>

#include		"libmy.h"

typedef struct		s_myerror_msg
{
  int			errno_val;
  char			*msg;
}			t_myerror_msg;

static t_myerror_msg	my_errno_msg [] =
  {
    {E2BIG, 		"Argument list too long.\n"},
    {EACCES, 		"Permission denied.\n"},
    {EADDRINUSE, 	"Address already in use.\n"},
    {EADDRNOTAVAIL, 	"Address not available.\n"},
    {EAFNOSUPPORT, 	"Address family not supported.\n"},
    {EAGAIN, 		"Resource temporarily  unavailable.\n"},
    {EALREADY, 		"Connection already in progress.\n"},
    {EBADE, 		"Invalid exchange.\n"},
    {EBADF, 		"Bad file descriptor.\n"},
    {EBADFD, 		"File descriptor in bad state.\n"},
    {EBADMSG, 		"Bad message.\n"},
    {EBADR, 		"Invalid request descriptor.\n"},
    {EBADRQC, 		"Invalid request code.\n"},
    {EBADSLT, 		"Invalid slot.\n"},
    {EBUSY, 		"Device or resource busy.\n"},
    {ECANCELED, 	"Operation canceled.\n"},
    {ECHILD, 		"No child processes.\n"},
    {ECHRNG, 		"Channel number out of range.\n"},
    {ECOMM, 		"Communication error on send.\n"},
    {ECONNABORTED, 	"Connection aborted.\n"},
    {ECONNREFUSED, 	"Connection refused.\n"},
    {ECONNRESET, 	"Connection reset.\n"},
    {EDEADLK, 		"Resource deadlock avoided.\n"},
    {EDEADLOCK, 	"Synonym for EDEADLK : Resource deadlock avoided.\n"},
    {EDESTADDRREQ, 	"Destination address required.\n"},
    {EDOM, 		"Mathematics argument out of domain of function.\n"},
    {EDQUOT, 		"Disk quota exceeded.\n"},
    {EEXIST, 		"File exists.\n"},
    {EFAULT, 		"Bad address.\n"},
    {EFBIG, 		"File too large.\n"},
    {EHOSTDOWN, 	"Host is down.\n"},
    {EHOSTUNREACH, 	"Host is unreachable.\n"},
    {EIDRM, 		"Identifier removed.\n"},
    {EILSEQ, 		"Illegal byte sequence.\n"},
    {EINPROGRESS, 	"Operation in progress.\n"},
    {EINTR, 		"Interrupted function call.\n"},
    {EINVAL, 		"Invalid argument.\n"},
    {EIO, 		"Input/output error.\n"},
    {EISCONN, 		"Socket is connected.\n"},
    {EISDIR, 		"Is a directory.\n"},
    {EISNAM, 		"Is a named type file.\n"},
    {EKEYEXPIRED, 	"Key has expired.\n"},
    {EKEYREJECTED, 	"Key was rejected by service.\n"},
    {EKEYREVOKED, 	"Key has been revoked.\n"},
    {EL2HLT, 		"Level 2 halted.\n"},
    {EL2NSYNC, 		"Level 2 not synchronized.\n"},
    {EL3HLT, 		"Level 3 halted.\n"},
    {EL3RST, 		"Level 3 halted.\n"},
    {ELIBACC, 		"Cannot access a needed shared library.\n"},
    {ELIBBAD, 		"Accessing a corrupted shared library.\n"},
    {ELIBMAX, 		"Attempting to link in too many shared libraries.\n"},
    {ELIBSCN, 		"Lib section in a.out corrupted.\n"},
    {ELIBEXEC, 		"Cannot exec a shared library directly.\n"},
    {ELOOP, 		"Too many levels of symbolic links.\n"},
    {EMEDIUMTYPE, 	"Wrong medium type.\n"},
    {EMFILE, 		"Too many open files.\n"},
    {EMLINK, 		"Too many links.\n"},
    {EMSGSIZE, 		"Message too long.\n"},
    {EMULTIHOP, 	"Multihop attempted.\n"},
    {ENAMETOOLONG, 	"Filename too long.\n"},
    {ENETDOWN, 		"Network is down.\n"},
    {ENETRESET, 	"Connection aborted by network.\n"},
    {ENETUNREACH, 	"Network unreachable.\n"},
    {ENFILE, 		"Too many open files in system.\n"},
    {ENOBUFS, 		"No buffer space available.\n"},
    {ENODATA,
"No message is available on the STREAM head read queue.\n"},
    {ENODEV, 		"No such device.\n"},
    {ENOENT, 		"No such file or directory.\n"},
    {ENOEXEC, 		"Exec format error.\n"},
    {ENOKEY, 		"Required key not available.\n"},
    {ENOLCK, 		"No locks available.\n"},
    {ENOLINK, 		"Link has been severed.\n"},
    {ENOMEDIUM, 	"No medium found.\n"},
    {ENOMEM, 		"Not enough space.\n"},
    {ENOMSG, 		"No message of the desired type.\n"},
    {ENONET, 		"Machine is not on the network.\n"},
    {ENOPKG, 		"Package not installed.\n"},
    {ENOPROTOOPT, 	"Protocol not available.\n"},
    {ENOSPC, 		"No space left on device.\n"},
    {ENOSR, 		"No STREAM resources.\n"},
    {ENOSTR, 		"Not a STREAM.\n"},
    {ENOSYS, 		"Function not implemented.\n"},
    {ENOTBLK, 		"Block device required.\n"},
    {ENOTCONN, 		"The socket is not connected.\n"},
    {ENOTDIR, 		"Not a directory.\n"},
    {ENOTEMPTY, 	"Directory not empty.\n"},
    {ENOTSOCK, 		"Not a socket.\n"},
    {ENOTSUP, 		"Operation not supported.\n"},
    {ENOTTY, 		"Inappropriate I/O control operation.\n"},
    {ENOTUNIQ, 		"Name not unique on network.\n"},
    {ENXIO, 		"No such device or address.\n"},
    {EOPNOTSUPP, 	"Operation not supported on socket.\n"},
    {EOVERFLOW, 	"Value too large to be stored in data type.\n"},
    {EPERM, 		"Operation not permitted.\n"},
    {EPFNOSUPPORT, 	"Protocol family not supported.\n"},
    {EPIPE, 		"Broken pipe.\n"},
    {EPROTO, 		"Protocol error.\n"},
    {EPROTONOSUPPORT, 	"Protocol not supported.\n"},
    {EPROTOTYPE, 	"Protocol wrong type for socket.\n"},
    {ERANGE, 		"Result too large.\n"},
    {EREMCHG, 		"Remote address changed.\n"},
    {EREMOTE, 		"Object is remote.\n"},
    {EREMOTEIO, 	"Remote I/O error.\n"},
    {ERESTART, 		"Interrupted system call should be restarted.\n"},
    {EROFS, 		"Read-only file system.\n"},
    {ESHUTDOWN, 	"Cannot send after transport endpoint shutdown.\n"},
    {ESPIPE, 		"Invalid seek.\n"},
    {ESOCKTNOSUPPORT, 	"Socket type not supported.\n"},
    {ESRCH, 		"No such process.\n"},
    {ESTALE, 		"Stale file handle.\n"},
    {ESTRPIPE, 		"Streams pipe error.\n"},
    {ETIME, 		"Timer expired.\n"},
    {ETIMEDOUT, 	"Connection timed out.\n"},
    {ETXTBSY, 		"Text file busy.\n"},
    {EUCLEAN, 		"Structure needs cleaning.\n"},
    {EUNATCH, 		"Protocol driver not attached.\n"},
    {EUSERS, 		"Too many users.\n"},
    {EWOULDBLOCK, 	"Operation would block.\n"},
    {EXDEV, 		"Improper link.\n"},
    {EXFULL, 		"Exchange full.\n"},
    {0, 		NULL}
  };

void			my_errno_aff(const int errnum,
				     const int fd)
{
  int			idx;

  idx = 0;
  while (my_errno_msg[idx].msg)
    {
      if (errnum == my_errno_msg[idx].errno_val)
	{
	  my_putstr(my_errno_msg[idx].msg, fd);
	  return ;
	}
      ++idx;
    }
  my_putstr("Unknow errno val ... \n", fd);
}
