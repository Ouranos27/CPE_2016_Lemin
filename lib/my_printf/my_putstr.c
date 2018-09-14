/*
** my_putstr.c for my_putstr in /home/amaury/CPool_Day04
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu>
** 
** Started on  Thu Oct  6 12:10:23 2016 Amaury Bernard
** Last update Tue Jan 17 15:49:12 2017 Amaury Bernard
*/

#include "unistd.h"
#include "my.h"

void	my_putstr(char *str, int *len)
{
  int	wlen;

  wlen = my_strlen(str);
  write(1, str, wlen);
  len += wlen;
}
