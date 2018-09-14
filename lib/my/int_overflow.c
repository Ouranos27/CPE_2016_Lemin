/*
** int_overflow.c for lib in /home/artha/CPE_2016_matchstick
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Tue Feb 21 09:49:13 2017 dylan renard
** Last update Tue Feb 21 10:58:35 2017 dylan renard
*/

#include "my.h"

int		int_overflow(char *num)
{
  char		*int_max;
  int		sign;

  int_max = "2147483647";
  sign = -1;
  if (num[0] == '-')
    {
      num = my_strdup(num + 1);
      int_max = "2147483646";
      sign = 1;
    }
  if (my_strlen(int_max) == my_strlen(num))
    {
      if (my_strcmp(int_max, num) == sign)
	return (1);
      return (0);
    }
  else if (my_strlen(int_max) > my_strlen(num)) return (0);
  return (1);
}
