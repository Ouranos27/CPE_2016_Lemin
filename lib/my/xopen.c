/*
** xopen.c for lib in /home/artha/lib_next/my
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Mon Jan 16 17:45:16 2017 dylan renard
** Last update Mon Jan 16 20:41:19 2017 dylan renard
*/

#include <fcntl.h>
#include "my.h"

int		xopen(const char *path, const int bitmask)
{
  int		fd;

  if ((fd = open(path, bitmask)) == -1)
    {
      my_puterr("Open failed for : ");
      my_puterr(path);
    }
  return (fd);
}
