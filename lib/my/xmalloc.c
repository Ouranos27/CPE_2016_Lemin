/*
** xmalloc.c for lib in /home/artha/lib_next/my
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Mon Jan 16 21:31:53 2017 dylan renard
** Last update Mon Jan 16 21:59:46 2017 dylan renard
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

void		*xmalloc(long size)
{
  void		*mem_zone;

  if ((mem_zone = malloc(size)) == NULL)
    {
      my_puterr("malloc of size ");
      my_puterr(to_string(size));
      my_puterr(" failled.");
      return (NULL);
    }
  return (mem_zone);
}
