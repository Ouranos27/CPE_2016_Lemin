/*
** xread.c for lib in /home/artha/lib_next/my
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Mon Jan 16 19:23:31 2017 dylan renard
** Last update Mon Jan 16 20:17:57 2017 dylan renard
*/

#include <unistd.h>
#include <fcntl.h>
#include "my.h"

int		xread(const int fd, void *buf, const int read_size)
{
  int		ret;

  if ((ret = read(fd, buf, read_size)) == -1)
    {
      my_puterr("Read failed for fd : ");
      my_puterr(to_string(fd));
    }
  return (ret);
}
