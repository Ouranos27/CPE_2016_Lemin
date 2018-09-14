/*
** my_putstr.c for my_putstr in /home/Artha77/CPool_Day04
**
** Made by dylan renard
** Login   <Artha77@epitech.net>
**
** Started on  Thu Oct  6 08:42:57 2016 dylan renard
** Last update Mon Jan 16 21:10:03 2017 dylan renard
*/

#include <unistd.h>
#include "my.h"

int	my_putstr(const char *str)
{
  int	len;

  len = my_strlen(str);
  if (len > 0)
    {
      if ((write(1, str, len)) == -1)
	return (-1);
    }
  return (len);
}
