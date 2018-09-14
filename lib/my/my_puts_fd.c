/*
** my_puts_fd.c for lib in /home/artha/lib_next/my
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Mon Jan 16 19:17:31 2017 dylan renard
** Last update Mon Jan 16 21:29:43 2017 dylan renard
*/

#include <unistd.h>
#include <fcntl.h>
#include "my.h"

int		my_puts_fd(char *str, const int fd)
{
  int		ret;

  if ((ret = my_putstr_fd(my_strcat(str, "\n"), fd)) == -1)
    return (-1);
  return (ret + 1);
}
