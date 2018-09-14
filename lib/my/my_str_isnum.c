/*
** my_str_isnum.c for my_str_isnum in /home/Artha77/CPool_Day06
**
** Made by dylan renard
** Login   <Artha77@epitech.net>
**
** Started on  Tue Oct 11 08:42:45 2016 dylan renard
** Last update Fri Feb 24 23:08:10 2017 dylan renard
*/

#include <stdlib.h>

static int	is_nm(char c)
{
  return (c >= '0' && c <= '9');
}

int		my_str_isnum(const char *str)
{
  int	i;

  i = 0;
  if (str == NULL || str[0] == 0)
    return (0);
  if (str[i] == '-' || str[i] == '+')
    return (0);
  if (i != 0 && str[i] == 0)
    return (0);
  while (str[i])
    {
      if (!is_nm(str[i++]))
	return (0);
    }
  return (1);
}
