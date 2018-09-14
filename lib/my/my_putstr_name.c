/*
** my_putstr_name.c for lib in /home/artha/lib_next/my
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Mon Jan 16 18:55:01 2017 dylan renard
** Last update Mon Jan 16 20:41:21 2017 dylan renard
*/

#include <unistd.h>
#include <fcntl.h>
#include "my.h"

int	my_putstr_name(const char *str, const char *name)
{
  int	len;
  int	fd;

  fd = xopen(name, O_WRONLY);
  if (fd == -1)
    return (1);
  len = my_strlen(str);
  if (len > 0)
    {
      if ((write(fd, str, len)) == -1)
	return (close(fd), -1);
    }
  close(fd);
  return (len);
}
