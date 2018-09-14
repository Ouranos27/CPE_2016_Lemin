/*
** my_putchar_name.c for lib in /home/artha/lib_next/my
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Mon Jan 16 17:36:07 2017 dylan renard
** Last update Mon Jan 16 21:10:01 2017 dylan renard
*/

#include <unistd.h>
#include <fcntl.h>
#include "my.h"

int		my_putchar_name(const char c, const char *name)
{
  int		fd;

  fd = xopen(name, O_WRONLY);
  if (fd == -1)
    return (0);
  if ((write(fd, &c, 1)) == -1)
    return (0);
  close(fd);
  return (1);
}
