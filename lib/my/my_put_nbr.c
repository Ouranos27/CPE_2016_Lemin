/*
** my_put_nbr.c for my_put_nbr in /home/Artha77/CPool_Day03
**
** Made by dylan renard
** Login   <Artha77@epitech.net>
**
** Started on  Wed Oct  5 13:14:08 2016 dylan renard
** Last update Sun Nov 27 10:39:21 2016 dylan renard
*/

#include "my.h"

int	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * (-1);
    }
  if (nb >= 10)
    {
      my_put_nbr(nb / 10);
      my_putchar((nb % 10) + 48);
    }
  else
    {
      my_putchar(nb + 48);
    }
  return (0);
}
