/*
** flags_2.c for flags_2 in /home/amaury.bernard/PSU_2016_my_printf
**
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.net>
**
** Started on  Sun Nov 20 20:58:17 2016 Amaury Bernard
** Last update Sun Apr 30 23:19:54 2017 dylan renard
*/

#include "my.h"

void	flag_x(va_list ap, int *len)
{
  my_put_hex(va_arg(ap, long long), "0123456789abcdef", len);
}

void	flag_X(va_list ap, int *len)
{
  my_put_hex(va_arg(ap, long long), "0123456789ABCDEF", len);
}

void	flag_b(va_list ap, int *len)
{
  my_dec_put_in_bin(va_arg(ap, long long), len);
}

void	flag_o(va_list ap, int *len)
{
  my_dec_put_in_oct(va_arg(ap, long long), len);
}

void	flag_mod(va_list ap, int *len)
{
  (void)ap;
  my_putchar('%', len);
}
