/*
** my_printf.c for printf in /home/amaury.bernard/PSU_2016_my_printf
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.net>
** 
** Started on  Tue Nov  8 14:18:19 2016 Amaury Bernard
** Last update Thu Feb  2 14:44:29 2017 Amaury Bernard
*/

#include "my.h"

void		decla_flags(t_flags *flags)
{
  flags[0].c = 's';
  flags[0].ftn = &flag_s;
  flags[1].c = 'S';
  flags[1].ftn = &flag_S;
  flags[2].c = 'c';
  flags[2].ftn = &flag_c;
  flags[3].c = 'd';
  flags[3].ftn = &flag_d;
  flags[4].c = 'i';
  flags[4].ftn = &flag_d;
  flags[5].c = 'p';
  flags[5].ftn = &flag_p;
  flags[6].c = 'x';
  flags[6].ftn = &flag_x;
  flags[7].c = 'X';
  flags[7].ftn = &flag_X;
  flags[8].c = 'b';
  flags[8].ftn = &flag_b;
  flags[9].c = 'o';
  flags[9].ftn = &flag_o;
  flags[10].c = '%';
  flags[10].ftn = &flag_mod;
  flags[11].c = 'e';
  flags[11].ftn = &flag_e;
}

int		my_printf(char *str, ...)
{
  int		i;
  va_list	ap;
  int		len[1];
  int		j;
  t_flags	flags[NB_FLAGS];

  decla_flags(flags);
  *len = 0;
  i = -1;
  va_start(ap, str);
  while (str[++i])
    {
      if (str[i] == '%' && str[++i] != 0)
	{
	  while (str[i] == ' ' && str[i] != '\0')
	    i++;
	  j = -1;
	  while (++j < NB_FLAGS)
	    if (str[i] == flags[j].c)
	      flags[j].ftn(ap, len);
	}
      else
	my_putchar(str[i], len);
    }
  return (*len);
}
