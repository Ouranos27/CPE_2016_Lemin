/*
** my_strlen.c for my_strlen in /home/Artha77/CPool_Day04
**
** Made by dylan renard
** Login   <Artha77@epitech.net>
**
** Started on  Thu Oct  6 08:59:36 2016 dylan renard
** Last update Mon Jan 16 20:08:14 2017 dylan renard
*/
#include <stdlib.h>

int	my_strlen(const char *str)
{
  int	i;

  if (str == NULL)
    return (0);
  i = 0;
  while (str && str[i])
    i++;
  return (i);
}
