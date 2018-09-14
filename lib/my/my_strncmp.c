/*
** my_strncmp.c for lib in /home/artha/tetris
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Sat Mar 18 19:08:07 2017 dylan renard
** Last update Sat Mar 18 19:11:07 2017 dylan renard
*/

#include <stdlib.h>

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  if (s1 == NULL || s2 == NULL || n < 0)
    return (-2);
  i = 0;
  while ((*(s1 + i) != '\0' && *(s1 + i) == *(s2 + i)) && n != i + 1)
    i = i + 1;
  if (*(s1 + i) > *(s2 + i))
    return (1);
  else if (*(s1 + i) < *(s2 + i))
    return (-1);
  return (0);
}
