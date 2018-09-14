/*
** my_puts_name_end.c for lib in /home/artha/lib_next/my
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Mon Jan 16 20:29:05 2017 dylan renard
** Last update Mon Jan 16 21:25:58 2017 dylan renard
*/

#include <unistd.h>
#include <fcntl.h>
#include "my.h"

int		my_puts_name_end(char *str, const char *name)
{
  int		ret;

  if ((ret = my_putstr_name_end(str, name)) == -1)
    return (-1);
  if ((my_putstr_name_end("\n", name)) == -1)
    return (-1);
  return (ret + 1);
}
