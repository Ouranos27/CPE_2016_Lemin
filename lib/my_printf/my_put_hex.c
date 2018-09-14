/*
** my_put_nbr.c for my_put_nbr in /home/amaury/CPool_Day07/lib/my
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu>
** 
** Started on  Wed Oct 12 09:25:24 2016 Amaury Bernard
** Last update Wed Feb  8 14:33:56 2017 Amaury Bernard
*/

#include <stdlib.h>
#include "my.h"

int	my_nbr_digits_hex(long long nb)
{
  int k;

  k = 1;
  while (nb > 15 || nb < -15)
    {
      nb = nb / 16;
      k++;
    }
  return (k);
}

void	my_put_hex(long long nb, char *hex, int *len)
{
  int	k;
  int	neg;
  char	*c;

  neg = 0;
  if (nb < 0)
    {
      neg = 1;
      nb = nb * -1;
    }
  k = my_nbr_digits_hex(nb) + neg;
  if ((c = malloc(k)) == NULL)
    return ;
  c[k] = '\0';
  --k;
  while ((k >= 0 && neg == 0) || (neg == 1 && k >= 1))
    {
      c[k--] = hex[nb % 16];
      nb = nb / 16;
    }
  if (neg == 1)
    c[0] = '-';
  my_putstr(c, len);
  free(c);
}
