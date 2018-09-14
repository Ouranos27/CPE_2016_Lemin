/*
** my_strdup.c for my_strdup in /home/Artha77/CPool_Day08/task01
**
** Made by dylan renard
** Login   <Artha77@epitech.net>
**
** Started on  Wed Oct 12 10:15:43 2016 dylan renard
** Last update Wed Jan 18 20:46:47 2017 dylan renard
*/

#include <stdlib.h>
#include "my.h"

char	*my_strdup(const char *src)
{
  char	*dest;
  int	len;

  if (src == NULL)
    return (NULL);
  len = my_strlen(src) + 1;
  if ((dest = malloc(len * sizeof(*src))) == NULL)
    return (NULL);
  my_strcpy(dest, src);
  return (dest);
}
