/*
** my_puts.c for lib in /home/artha/lib_next/my
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Mon Jan 16 19:12:45 2017 dylan renard
** Last update Mon Jan 16 21:10:05 2017 dylan renard
*/

#include <unistd.h>
#include <fcntl.h>
#include "my.h"

int		my_puts(const char *str)
{
  int		ret;

  if ((ret = my_putstr(str)) == -1)
    return (-1);
  if ((my_putchar('\n')) == 0)
    return (-1);
  return (ret + 1);
}
