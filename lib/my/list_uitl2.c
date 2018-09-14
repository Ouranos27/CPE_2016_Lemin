/*
** list_uitl2.c for push_swap in /home/artha/pushswap
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Sun Nov 27 12:48:32 2016 dylan renard
** Last update Fri Feb 24 09:52:40 2017 dylan renard
*/

#include "my.h"
#include "list.h"
#include <stdlib.h>

void		free_list(t_ld *list)
{
  t_list	*tmp;

  tmp = list->next;
  while (tmp != NULL)
    {
      tmp = tmp->next;
      if (tmp == NULL)
	free(list->end);
      else
	free(tmp->prev);
    }
  free(list);
}

t_ld		*pop_list(t_ld  *list)
{
  t_list	*tmp;

  tmp = list->next;
  if (tmp != NULL)
    {
      if (tmp->next == NULL)
	{
	  free(list->next);
	  list->next = NULL;
 	  list->end = NULL;
	}
      else
	{
	  list->next = tmp->next;
	  free(tmp);
	  (list->next)->prev = NULL;
	}
    }
  return (list);
}
