/*
** my_put_nbr.c for my_put_nbr in /home/amaury/CPool_Day07/lib/my
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu>
** 
** Started on  Wed Oct 12 09:25:24 2016 Amaury Bernard
** Last update Sun Nov 20 19:01:22 2016 Amaury Bernard
*/

#include "my.h"

void	my_put_adr(long long nb, int *len)
{
  my_putchar('0', len);
  my_putchar('x', len);
  my_put_hex(nb, "0123456789abcdef", len);
}
