/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/Artha77/CPool_Day08/task04
**
** Made by dylan renard
** Login   <Artha77@epitech.net>
**
** Started on  Thu Oct 13 17:22:36 2016 dylan renard
** Last update Sun Jan 22 21:38:43 2017 dylan renard
*/

#include <stdlib.h>
#include "my.h"

static char	*space_purge(char *str)
{
  int		i;
  char		prev;
  char		*final;
  int		draw;
  int		j;

  j = -1;
  i = 0;
  if ((final = malloc((my_strlen(str) + 1) * sizeof(char))) == NULL)
    return (NULL);
  prev = ' ';
  draw = 1;
  while (str[i] != '\0')
      {
	if (prev == ' ' && str[i] == ' ')
	  draw = 0;
	else
	  draw = 1;
	prev = str[i];
	if (draw)
	  final[++j] = str[i];
	i++;
      }
  final[++j] = '\0';
  return (final);
}

static int	nb_word(char *str)
{
  char		prev;
  int		i;
  int		count;
  int		bypass;

  prev = ' ';
  i = 0;
  bypass = 0;
  count = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '"')
	{
	  count += bypass;
	  bypass = (bypass == 0) ? 1 : 0;
	}
      if (!bypass)
	{
	  if (prev == ' ' && str[i] != ' ')
	    count++;
	}
      prev = str[i];
      i++;
    }
  return (count);
}

static char	**do_quote(char *str, char **tab, int j, int k)
{
  int		i;

  i = j + 1;
  j++;
  while (str[i] != '"' && str[i] != '\0')
    {
      i++;
    }
  tab[k] = malloc((i - j) * sizeof(char));
  tab[k] = my_strncpy(tab[k], (str + j), (i - j));
  return (tab);
}

static char	**wordtab(char **tab, char *str, int size, int k)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (k != size)
    {
      if (str[j] == ' ' || str[j] == '\0')
	{
	  tab[k] = malloc((j - i) * sizeof(char));
	  tab[k] = my_strncpy(tab[k], (str + i), (j - i));
	  i = j + 1;
	  k++;
	}
      if (str[j] == '"')
	{
	  tab = do_quote(str, tab, j, k);
	  j += my_strlen(tab[++k]) + 1;
	  i = j;
	}
      j++;
    }
  tab[k + 1] = NULL;
  return (tab);
}

char	**my_str_to_wordtab(char *str)
{
  int	size;
  char	**tab;

  str = tab_to_space(str);
  str = space_purge(str);
  size = nb_word(str);
  tab = malloc((size + 1) * sizeof(char  *));
  tab = wordtab(tab, str, size, 0);
  return (tab);
}
