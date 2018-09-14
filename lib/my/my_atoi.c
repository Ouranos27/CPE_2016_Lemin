/*
** my_atoi.c for my_atoi in /home/artha/signal_test
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Fri Feb 17 12:38:33 2017 dylan renard
** Last update Fri Feb 17 12:52:31 2017 dylan renard
*/

#include "my.h"

int		my_atoi(char *nb)
{
  int		final;
  int		sign;
  int		i;
  int		j;

  final = 0;
  sign = 1;
  j = 1;
  if (nb[0] == '-')
    {
      sign = -1;
      nb++;
    }
  i = my_strlen(nb) - 1;
  while (i != -1)
    {
      final = final + ((nb[i] - '0') * j);
      i--;
      j *= 10;
    }
  return (final * sign);
}
