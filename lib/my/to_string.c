/*
** to_string.c for lib in /home/artha/lib_next/my
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Mon Jan 16 19:30:05 2017 dylan renard
** Last update Sun Feb 19 13:25:29 2017 dylan renard
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my.h"

char		*to_string(int nbr)
{
  char		*str;
  char		*tmp;

  str = NULL;
  tmp = my_strdup(" ");
  while (nbr >= 10)
    {
      tmp[0] = (char)((nbr % 10) + '0');
      str = my_strcat(tmp , str);
      nbr /= 10;
    }
  tmp[0] = (char)((nbr % 10) + '0');
  str = my_strcat(tmp , str);
  free(tmp);
  return (str);
}
