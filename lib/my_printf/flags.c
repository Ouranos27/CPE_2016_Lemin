/*
** flags.c for flags in /home/amaury.bernard/PSU_2016_my_printf
**
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.net>
**
** Started on  Thu Nov 17 16:34:08 2016 Amaury Bernard
** Last update Sun Apr 30 23:20:24 2017 dylan renard
*/

#include "my.h"

void	flag_s(va_list ap, int *len)
{
  my_putstr(va_arg(ap, char *), len);
}

void	flag_S(va_list ap, int *len)
{
  my_putstr_all(va_arg(ap, char *), len);
}

void	flag_c(va_list ap, int *len)
{
  my_putchar(va_arg(ap, int), len);
}

void	flag_d(va_list ap, int *len)
{
  my_put_nbr(va_arg(ap, long long), len);
}

void	flag_p(va_list ap, int *len)
{
  my_put_adr(va_arg(ap, unsigned long), len);
}
