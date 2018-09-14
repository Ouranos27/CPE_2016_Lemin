/*
** my_strcat.c for lib in /home/artha/lib_next/my
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Mon Jan 16 19:34:17 2017 dylan renard
** Last update Mon Jan 16 19:36:15 2017 dylan renard
*/

#include <stdlib.h>
#include "my.h"

char		*my_strcat(char *base, char *to_add)
{
  char			*final;
  int			i;
  int			j;
  int			len_base;
  int			len_add;

  i = -1;
  j = -1;
  len_base = my_strlen(base);
  len_add = my_strlen(to_add);
  if ((final = malloc(len_base + len_add + 1)) == NULL)
    return (NULL);
  while (j != (len_base - 1))
    final[++i] = base[++j];
  j = -1;
  while (j != (len_add - 1))
    final[++i] = to_add[++j];
  final[i + 1] = '\0';
  return (final);
}
