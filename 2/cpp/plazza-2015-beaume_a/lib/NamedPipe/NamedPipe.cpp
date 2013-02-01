#include		<sys/types.h>
#include		<sys/stat.h>
#include		<fcntl.h>
#include		<unistd.h>
#include		<iostream>
#include		<sstream>

#include		"NamedPipe.h"

NamedPipe::~NamedPipe()
{
  close(this->_fd);
}

NamedPipe::NamedPipe()
{
  std::stringstream	ss;

  ss << "/tmp/" << int(getppid());
  this->_fd = mkfifo(ss.str().c_str(), 0600);
  if (this->_fd == -1)
    throw Error("Mkfifo fail");
}

NamedPipe::NamedPipe(const char *fileName)
{
  this->_fd = mkfifo(fileName, 0600);
  if (this->_fd == -1)
    throw Error("Mkfifo fail");
}

void			NamedPipe::_write(const std::string &str) const
{
  int			ret;

  ret = write(this->_fd, str.c_str(), str.size());
  if (ret == -1)
    throw Error("Write fail");
}

void			NamedPipe::_write(int i) const
{
  int			ret;

  ret = write(this->_fd, &i, sizeof(&i));
  if (ret == -1)
    throw Error("Write fail");
}

void			NamedPipe::_read(char *str, size_t len) const
{
  int			ret;

  ret = read(this->_fd, str, len);
  if (-1 == ret)
    throw Error("Read fail");
}

NamedPipe		&operator <<(NamedPipe &pipe, const std::string &str)
{
  pipe._write(str);
  return pipe;
}
