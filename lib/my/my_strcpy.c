/*
** my_strcpy.c for my_strcpy in /home/Artha77/CPool_Day06
**
** Made by dylan renard
** Login   <Artha77@epitech.net>
**
** Started on  Mon Oct 10 07:07:31 2016 dylan renard
** Last update Wed Jan 18 20:49:51 2017 dylan renard
*/

#include <stdlib.h>

char	*my_strcpy(char *dest, const char *src)
{
  int	i;

  if (dest == NULL || src == NULL)
    return (NULL);
  i = 0;
  while (*(src + i) != '\0')
    {
      *(dest + i) = *(src + i);
      i = i + 1;
    }
  *(dest + i) = '\0';
  return (dest);
}
