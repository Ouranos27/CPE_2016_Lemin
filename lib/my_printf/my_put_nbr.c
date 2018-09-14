/*
** my_put_nbr.c for my_put_nbr in /home/amaury/CPool_Day07/lib/my
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu>
** 
** Started on  Wed Oct 12 09:25:24 2016 Amaury Bernard
** Last update Wed Feb  8 14:32:26 2017 Amaury Bernard
*/

#include <stdlib.h>
#include "my.h"

void	my_put_nbr(long long nb, int *len)
{
  if (nb < 0)
    {
      my_putchar('-', len);
      nb = nb * -1;
    }
  if (nb > 9)
    {
      my_put_nbr(nb /10, len);
    }
  my_putchar('0' + (nb % 10), len);
}
