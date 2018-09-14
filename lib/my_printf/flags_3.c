/*
** flags_3.c for my_printf in /home/amaury/delivery/PSU_2016_navy/lib/my_printf
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu>
** 
** Started on  Thu Feb  2 14:35:21 2017 Amaury Bernard
** Last update Thu Feb  2 14:39:12 2017 Amaury Bernard
*/

#include "my.h"

void	flag_e(va_list ap, int *len)
{
  my_putstr_err(va_arg(ap, char *), len);
}
