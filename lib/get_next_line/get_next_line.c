/*
** get_next_line.c for get_next_line in /home/amaury/delivery/CPE_2016_getnextline
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu>
** 
** Started on  Tue Jan  3 13:14:17 2017 Amaury Bernard
** Last update Wed Jan 18 14:50:51 2017 Amaury Bernard
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char	*gnl_strcpy(char *dest, char *src)
{
  char	c;
  int	i;

  if (!dest || !src)
    return (NULL);
  i = 0;
  while (src[i] != '\0')
    {
      c = src[i];
      dest[i] = c;
      ++i;
    }
  dest[i] = '\0';
  return (dest);
}

/*
** Answer to "There is a '\n' in str ?" by:
**   a string rest, contening a copy of the data after the '\n'
**   NULL, if not
*/
char	*there_is_bn(char *str,  int *writed)
{
  int	i;
  char	*rest;

  rest = NULL;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\n')
	{
	  if ((rest = malloc(*writed + 1)) == NULL)
	    return (NULL);
	  str[i] = '\0';
	  gnl_strcpy(rest, &str[++i]);
	  *writed -= i;
	  return (rest);
	}
      ++i;
    }
  return (NULL);
}

char	*reader(const int fd, char *str, char **rest, int *writed)
{
  char	*new;
  int	rt_read;

  if (*rest != NULL && str == NULL)
    {
      if ((str = malloc(*writed + 1)) == NULL)
	return (NULL);
      gnl_strcpy(str, *rest);
      free(*rest);
    }
  if ((new = malloc(*writed + READ_SIZE + 1)) == NULL)
    return (NULL);
  gnl_strcpy(new, str);
  free(str);
  rt_read = 0;
  if (*rest == NULL && (rt_read = read(fd, new + *writed, READ_SIZE)) < 0)
    return (NULL);
  if (*rest == NULL && rt_read == 0)
    *writed = -1;
  *writed += rt_read;
  new[*writed] = '\0';
  if ((*rest != NULL || rt_read != 0) && !(*rest = there_is_bn(new, writed)))
    new = reader(fd, new, rest, writed);
  return (new);
}

char		*get_next_line(const int fd)
{
  char		*str;
  char		*rt;
  static int	writed = 0;
  static char	*rest = NULL;

  if (writed == -1)
    return (NULL);
  if (READ_SIZE <= 0)
    return (NULL);
  str = NULL;
  rt = reader(fd, str, &rest, &writed);
  return (rt);
}
