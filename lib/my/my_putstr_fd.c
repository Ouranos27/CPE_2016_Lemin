/*
** my_putstr_fd.c for lib in /home/artha/lib_next/my
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Mon Jan 16 17:54:33 2017 dylan renard
** Last update Mon Jan 16 20:42:28 2017 dylan renard
*/

#include <unistd.h>
#include "my.h"

int	my_putstr_fd(const char *str, const int fd)
{
  int	len;

  len = my_strlen(str);
  if (len > 0)
    {
      if ((write(fd, str, len)) == -1)
	return (-1);
    }
  return (len);
}
