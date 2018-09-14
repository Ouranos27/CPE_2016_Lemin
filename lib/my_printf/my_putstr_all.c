/*
** my_putstr.c for my_putstr in /home/amaury/CPool_Day04
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu>
** 
** Started on  Thu Oct  6 12:10:23 2016 Amaury Bernard
** Last update Sun Nov 20 19:03:20 2016 Amaury Bernard
*/

#include "my.h"

void	my_putstr_all(char *str, int *len)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] > 31 && str[i] < 127)
	my_putchar(str[i], len);
      else
	{
	  my_putchar('\\', len);
	  my_dec_put_in_oct(str[i], len);
	}
      i++;
    }
}
