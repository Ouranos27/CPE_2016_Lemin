/*
** tab_to_space.c for lib_next in /home/artha/PSU_2016_minishell1
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Sun Jan 22 20:44:49 2017 dylan renard
** Last update Sun Jan 22 20:55:07 2017 dylan renard
*/

#include "my.h"

char		*tab_to_space(char *str)
{
  char		*final;
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == 9)
	final[i] = ' ';
      else
	final[i] = str[i];
      i++;
    }
  return (final);
}
